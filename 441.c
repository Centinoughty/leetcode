// Arranging coins
// EASY

#include <stdio.h>

int arrangeCoins(int n) {
  long int val = sqrt((long)8 * n + 1);
  return (val - 1) / 2;
}