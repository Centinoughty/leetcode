// Gas station
// MEDIUM

#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
  int tank = 0, start = 0;
  int totalCost = 0, totalGas = 0;
  for (int i = 0; i < gasSize; i ++) {
    totalCost += cost[i];
    totalGas += gas[i];
    tank += gas[i] - cost[i];
    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }

  if (totalCost > totalGas) {
    return -1;
  }

  return start;
}