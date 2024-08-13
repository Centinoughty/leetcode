// Crawler log folder
// EASY

#include <stdio.h>

int minOperations(char** logs, int logsSize) {
  int count = 0;
  for (int i = 0; i < logsSize; i ++) {
    if (logs[i][0] == '.') {
      if (logs[i][1] == '.' && count > 0) {
        count --;
      }
    } else {
      count ++;
    }
  }

  return count;
}
