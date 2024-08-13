// Find the first player to win k games in a row
// MEDIUM

#include <stdio.h>

int findWinningPlayer(int* skills, int skillsSize, int k) {
  int winCount = 0;
  int index = 0;

  for (int i = 1; i < skillsSize && winCount < k; i ++) {
    if (skills[i] > skills[index]) {
      index = i;
      winCount = 1;
    } else {
      winCount++;
    }
  }

  return index;
}