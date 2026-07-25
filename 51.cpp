// N-Queens
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> st;
        string s(n, '.');
        for (int i = 0; i < n; i ++) {
            st.push_back(s);
        }

        dfs(0, n, st);
        return res;
    }

private:
    vector<vector<string>> res;

    void dfs(int col, int n, vector<string>& st) {
        if (col == n) {
            res.push_back(st);
            return;
        }

        for (int i = 0; i < n; i ++) {
            if (isFree(i, col, n, st)) {
                st[i][col] = 'Q';
                dfs(col + 1, n, st);
                st[i][col] = '.';
            }
        }
    }

    bool isFree(int row, int col, int n, vector<string>& st) {
        int tempR = row;
        int tempC = col;
        while (tempR >= 0 && tempC >= 0) {
            if (st[tempR --][tempC --] == 'Q') {
                return false;
            }
        }

        tempR = row;
        tempC = col;
        while (tempC >= 0) {
            if (st[tempR][tempC --] == 'Q') {
                return false;
            }
        }

        tempC = col;
        while (tempR < n && tempC >= 0) {
            if (st[tempR ++][tempC --] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

// Final
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col.resize(n, false);

        diagL.resize(2 * n - 1, false);
        diagR.resize(2 * n - 1, false);

        solve(board, 0);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<bool> col, diagL, diagR;

    void solve(vector<string>& board, int i) {
        int n = board.size();
        if (i == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c ++) {
            if (isSafe(board, i, c)) {
                board[i][c] = 'Q';
                col[c] = diagL[i + c] = diagR[i + n - c - 1] = true;

                solve(board, i + 1);

                board[i][c] = '.';
                col[c] = diagL[i + c] = diagR[i + n - c - 1] = false;
            }
        }

        return;
    }

    bool isSafe(vector<string>& board, int i, int j) {
        int n = board.size();

        if (col[j] || diagL[i + j] || diagR[i + n - j - 1]) return false;

        for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x ++) {
            for (int y = max(0, j - 1); y <= min(n - 1, j + 1); y ++) {
                if (x == i && y == j) continue;
                if (board[x][y] == 'Q') return false;
            }
        }

        return true;
    }
};
