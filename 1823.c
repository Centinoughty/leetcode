// Find the winner of the circular game
// MEDIUM

#include <stdio.h>

int f (int n, int k) {
  int res = 0;
  for (int i = 2; i <= n; i ++) {
      res = (res + k) % i;
  }

  return res;
}

int findTheWinner(int n, int k) {
  return f(n, k) + 1;
}
