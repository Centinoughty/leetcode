// Surrounded regions
// MEDIUM

#include <stdio.h>

void dfs (char** board, int boardSize, int* boardColSize, int i, int j) {
  if (i < 0 || j < 0 || i == boardSize || j == boardColSize[i]) {
    return;
  }

  if (board[i][j] != 'O') {
    return;
  } 

  board[i][j] = 'M';
  dfs(board, boardSize, boardColSize, i + 1, j);
  dfs(board, boardSize, boardColSize, i - 1, j);
  dfs(board, boardSize, boardColSize, i, j + 1);
  dfs(board, boardSize, boardColSize, i, j - 1);
}

void solve(char** board, int boardSize, int* boardColSize) {
  for (int i = 0; i < boardSize; i ++) {
    for (int j = 0; j < boardColSize[i]; j ++) {
      if (i == 0 || j == 0 || i == boardSize - 1 || j == boardColSize[i] - 1) {
        dfs(board, boardSize, boardColSize, i, j);
      }
    }
  }

  for (int i = 0; i < boardSize; i ++) {
    for (int j = 0; j < boardColSize[i]; j ++) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      } else if (board[i][j] == 'M') {
        board[i][j] = 'O';
      }
    }
  }
}
