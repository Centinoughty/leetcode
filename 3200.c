// Maximum height of a triangle
// EASY

#include <stdio.h>

int maxHeightOfTriangle(int red, int blue) {
  int rows1 = 0, rows2 = 0;
  int x = red, y = blue;
  int current = 0;
  
  while (1) {
    rows1 += 1;
    if (current == 0) {
      if (red >= rows1) {
        red -= rows1;
      } else {
        break;
      }
        
      current ^= 1;
    } else {
      if (blue >= rows1) {
        blue -= rows1;
      } else {
        break;
      }
      
      current ^= 1;
    }
  }
  
  current = 1;
  while (1) {
    rows2 += 1;
    if (current == 0) {
      if (x >= rows2) {
        x -= rows2;
      } else {
        break;
      }
      
      current ^= 1;
    } else {
      if (y >= rows2) {
        y -= rows2;
      } else {
        break;
      }
      
      current ^= 1;
    }
  }
  
  return fmax(rows1 - 1, rows2 - 1);
}