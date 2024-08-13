// Fizz buzz
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
  char** strings = (char**)malloc(n * sizeof(char*));

  for (int i = 0; i < n; i ++) {
    int x = i + 1;
    if (x % 15 == 0) {
      strings[i] = (char*)malloc(9 * sizeof(char));
      strcpy(strings[i], "FizzBuzz");
    } else if (x % 3 == 0) {
      strings[i] = (char*)malloc(5 * sizeof(char));
      strcpy(strings[i], "Fizz");
    } else if (x % 5 == 0) {
      strings[i] = (char*)malloc(5 * sizeof(char));
      strcpy(strings[i], "Buzz");
    } else {
      strings[i] = (char*)malloc(9 * sizeof(char));
      sprintf(strings[i], "%d", x);
    }
  }

  *returnSize = n;
  return strings;
}