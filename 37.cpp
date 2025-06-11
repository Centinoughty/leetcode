// Sudoku solver
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board.size(); j ++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k ++) {
                        if (isSafe(i, j, board, k)) {
                            board[i][j] = k;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < board.size(); i ++) {
            if (board[i][col] == val) {
                return false;
            }

            if (board[row][i] == val) {
                return false;
            }
        }

        int startR = 3 * (row / 3), startC = 3 * (col / 3);
        for (int i = startR; i < startR + 3; i ++) {
            for (int j = startC; j < startC + 3; j ++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }

        return true;
    }
};
