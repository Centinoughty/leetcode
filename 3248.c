// Snake in a matrix
// EASY

#include <stdio.h>

int finalPositionOfSnake(int n, char** commands, int commandsSize) {
  int pos = 0;
  for (int i = 0; i < commandsSize; i ++) {
    switch (commands[i][0]) {
      case 'U':
        pos -= n;
        break;
      
      case 'D':
        pos += n;
        break;
      
      case 'R':
        pos += 1;
        break;
      
      case 'L':
        pos -= 1;
        break;
    }
  }
  
  return pos;
}
