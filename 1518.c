// Water bottles
// EASY

#include <stdio.h>

int numWaterBottles(int numBottles, int numExchange) {
  int count = numBottles;
  int used = numBottles, unused = 0;
  int rem = 0;

  while (1) {
    rem = used % numExchange;
    unused = used / numExchange;
    count += unused;
    used = unused + rem;
    if (unused == 0 && used < numExchange) {
      break;
    }
  }

  return count;
}
