// Find words containing charecter

#include <stdio.h>

int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* array = (int*)malloc(wordsSize * sizeof(int));
    int pos = 0;
    int count = 0;
    for (int i = 0; i < wordsSize; i ++) {
        int j = 0;
        while (words[i][j] != '\0') {
            if (words[i][j] == x) {
                array[pos ++] = i;
                count ++;
                break;
            }

            j ++;
        }
    }

    *returnSize = count;
    return array;
}