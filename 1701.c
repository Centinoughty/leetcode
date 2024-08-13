// Average waiting time
// MEDIUM

#include <stdio.h>

double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
  int presentTime = 0;
  long waitingTime = 0;

  for (int i = 0; i < customersSize; i ++) {
    if (presentTime < customers[i][0]) {
      presentTime = customers[i][0];
    }

    waitingTime += presentTime + customers[i][1] - customers[i][0];
    presentTime += customers[i][1];
  }

  return (double)waitingTime / customersSize;
}
