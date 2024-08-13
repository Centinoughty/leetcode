// Alternating groups I
// EASY

#include<stdio.h>

int numberOfAlternatingGroups(int* colors, int colorsSize) {
  int count = 0;
  for (int i = 0; i < colorsSize - 2; i ++) {
    if (colors[i] ^ colors[i + 1] == 1 && colors[i] ^ colors[i + 2] == 0) {
      count ++;
    }
  }
  
  if (colors[0] ^ colors[colorsSize - 2] == 0 && colors[0] ^ colors[colorsSize - 1] == 1) {
    count ++;
  }
  
  if (colors[1] ^ colors[colorsSize - 1] == 0 && colors[0] ^ colors[1] == 1) {
    count ++;
  }
  
  return count;
}
