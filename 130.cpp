// Surrounded Regions
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        if (x < 0 || y < 0 || x == m || y == n) return;

        if (board[x][y] != 'O') return;
        board[x][y] = 'Y';

        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
};
