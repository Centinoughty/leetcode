// Rotate string
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* generatePiTable (char* p) {
  int n = strlen(p);
  int j = 0;
  int* piTable = (int*)malloc((n + 1) * sizeof(int));
  piTable[0] = 0;

  for (int i = 1; i < n; i ++) {
    while (j > 0 && p[j] != p[i]) {
      j = piTable[j - 1];
    }

    if (p[j] == p[i]) {
      j ++;
    }

    piTable[i] = j;
  }

  return piTable;
}

bool kmp (char* t, char* p) {
  int m = strlen(t);
  int n = strlen(p);

  int* piTable = generatePiTable(p);
  int j = 0;
  for (int i = 0; i < m; i ++) {
    while (j > 0 && p[j] != t[i]) {
      j = piTable[j - 1];
    }

    if (p[j] == t[i]) {
      j ++;
    }

    if (j == n) {
      return true;
    }
  }

  return false;
}

bool rotateString(char* s, char* goal) {
  int lengthS = strlen(s);
  int lengthGoal = strlen(goal);
  char* t = (char*)malloc((2 * lengthGoal + 1) * sizeof(char));
  t[0] = '\0';
  strcat(t, goal);
  strcat(t, goal);
  return lengthS == lengthGoal && kmp(t, s);
}
