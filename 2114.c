// Maximum number of words found in a sentence
// EASY

#include <stdio.h>

int mostWordsFound(char** sentences, int sentencesSize) {
    int maximum = 0;
    for (int i = 0; i < sentencesSize; i ++) {
        int count = 0;
        int j = 0;
        while (sentences[i][j] != '\0') {
            if (sentences[i][j] == ' ') {
                count ++;
            }

            j ++;
        }

        maximum = count > maximum ? count : maximum;
    }

    return maximum + 1;
}   