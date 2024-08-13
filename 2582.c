// Pass the pillow
// EASY

#include <stdio.h>

int passThePillow(int n, int time) {
  int group = time / (n - 1);
  return group % 2 ? n - time % (n - 1) : time % (n - 1) + 1;
}