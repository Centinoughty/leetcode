// Happy number
// EASY

#include <stdio.h>
#include <stdbool.h>

int squareSum (int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10) * (n % 10);
    n /= 10;
  }

  return sum;
}

bool isHappy(int n) {
  int slow = squareSum(n);
  int fast = squareSum(squareSum(n));

  while (slow != fast) {
    slow = squareSum(slow);
    fast = squareSum(squareSum(fast));
  }

  return slow == 1;
}