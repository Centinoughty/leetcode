// Partitioning into minimum number of deci-binary numbers
// MEDIUM

#include <stdio.h>

int minPartitions(char* n) {
  int i = 0;
  int max = 0;

  while (n[i ++] != '\0') {
      max = n[i] - '0' > max ? n[i] - '0' : max;
  }

  return max;
}