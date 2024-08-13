// Game of life
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int countNeighbours(int** board, int x, int y) {
  int count = 0;

  for (int i = x - 1; i < x + 2; i++) {
    for (int j = y - 1; j < y + 2; j++) {
      if (!(i == x && j == y)) {
        if (board[i][j] == 1) {
          count++;
        }
      }
    }
  }

  return count;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
  int** array = (int**)calloc(boardSize + 2, sizeof(int*));
  for (int i = 0; i < boardSize + 2; i++) {
    array[i] = (int*)calloc((*boardColSize + 2), sizeof(int));
  }

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < *boardColSize; j++) {
      array[i + 1][j + 1] = board[i][j];
    }
  }

  for (int i = 1; i < boardSize + 1; i++) {
    for (int j = 1; j < *boardColSize + 1; j++) {
      int temp = countNeighbours(array, i, j);
      if (array[i][j] == 1) {
        if (temp == 2 || temp == 3) {
          board[i - 1][j - 1] = 1;
        } else {
          board[i - 1][j - 1] = 0;
        }
      } else {
        if (temp == 3) {
          board[i - 1][j - 1] = 1;
        }
      }
    }
  }

  for (int i = 0; i < boardSize + 2; i ++) {
    free(array[i]);
  }

  free(array);
}
