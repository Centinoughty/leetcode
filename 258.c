// Add digits
// EASY

#include <stdio.h>

int addDigits(int num) {
  if (num < 9) {
    return num;
  } else {
    return (num - 1) % 9 + 1;
  }
}