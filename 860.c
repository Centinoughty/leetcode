// Lemonade challenge
// EASY

#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
  int fiveCount = 0;
  int tenCount = 0;
  int twentyCount = 0;

  for (int i = 0; i < billsSize; i ++) {
    if (bills[i] == 5) {
      fiveCount ++;
    } else if (bills[i] == 10) {
      tenCount ++;
      if (fiveCount) {
        fiveCount --;
      } else {
        return false;
      }
    } else {
      twentyCount ++;
      if (tenCount) {
        tenCount --;
        if (fiveCount) {
          fiveCount --;
        } else {
          return false;
        }
      } else if (fiveCount > 2) {
        fiveCount -= 3;
      } else {
        return false;
      }
    }
  }

  return true;
}
