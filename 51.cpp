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
