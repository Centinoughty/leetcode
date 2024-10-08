// Find the smallest letter greater than target
// EASY

#include <stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target) {
  int left = 0;
  int right = lettersSize - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (letters[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return letters[left % lettersSize];
}