// Valid sudoku
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

void resetArray (int* nums) {
  for (int i = 0; i < 9; i ++) {
    nums[i] = 0;
  }
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
  int* array = (int*)malloc(9 * sizeof(int));

  for (int i = 0; i < 9; i ++) {
    resetArray(array);
    for (int j = 0; j < 9; j ++) {
      if (isdigit(board[i][j])){
        int num = board[i][j] - '0';
        array[num - 1] ++;
        if (array[num - 1] > 1) {
          return false;
        }
      }
    }
  }

  for (int i = 0; i < 9; i ++) {
    resetArray(array);
    for (int j = 0; j < 9; j ++) {
      if (isdigit(board[j][i])) {
        int num = board[j][i] - '0';
        array[num - 1] ++;
        if (array[num - 1] > 1) {
          return false;
        }
      }
    }
  }

  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      resetArray(array);
      for (int r = i; r < i + 3; r ++) {
        for (int s = j; s < j + 3; s ++) {
          if (isdigit(board[r][s])) {
            int num = board[r][s] - '0';
            array[num - 1] ++;
            if (array[num - 1] > 1) {
              return false;
            }
          }
        }
      }
    }
  }

  free(array);
  return true;
}