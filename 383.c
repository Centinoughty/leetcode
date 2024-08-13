// Ransom note
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
  int* array = (int*)calloc(26, sizeof(int));

  for (int i = 0; magazine[i] != '\0'; i ++) {
    array[magazine[i] - 'a'] ++;
  }

  for (int i = 0; ransomNote[i] != '\0'; i ++) {
    if (array[ransomNote[i] - 'a'] > 0) {
      array[ransomNote[i] - 'a'] --;
    } else {
      return false;
    }
  }

  return true;
}
