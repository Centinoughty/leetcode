// Find the winning player in the coin game
// EASY

#include <stdio.h>

char* losingPlayer(int x, int y) {
  int flag = 0;
  
  while (x >= 1 && y >= 4) {
    x -= 1;
    y -= 4;
    flag ^= 1;
  }
  
  if (flag) return "Alice";
  return "Bob";
}
