// Relative ranks
// EASY

#include <stdio.h>
#include <stdlib.h>

char **findRelativeRanks(int *score, int scoreSize, int *returnSize) {
    char **string = (char**)malloc(scoreSize * sizeof(char*));

    int *array = (int*)malloc(scoreSize * sizeof(int));
    for (int i = 0; i < scoreSize; i ++) {
        array[i] = i;
    }
    for (int i = 0; i < scoreSize - 1; i ++) {
        for (int j = 0; j < scoreSize - i - 1; j ++) {
            if (score[array[j]] < score[array[j + 1]]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < scoreSize; i ++) {
        if (i == 0) {
            string[array[i]] = "Gold Medal";
        } else if (i == 1) {
            string[array[i]] = "Silver Medal";
        } else if (i == 2) {
            string[array[i]] = "Bronze Medal";
        } else {
            char *rank = (char*)malloc(5 * sizeof(char));
            sprintf(rank, "%d", i + 1);
            string[array[i]] = rank;
        }
    }

    free(array);
    *returnSize = scoreSize;
    return string;
}