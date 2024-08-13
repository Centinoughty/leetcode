// Find the encrypted string
// EASY

#include <stdio.h>
#include <string.h>

char* getEncryptedString(char* s, int k) {
  int length = strlen(s);
  char* string = (char*)malloc((length + 1) * sizeof(char));
  int pos = 0;
  int i = 0;
  
  while (i < length) {
    string[pos ++] = s[(i + k) % length];
    i ++;
  }
  
  string[pos ++] = '\0';
  return string;
}
