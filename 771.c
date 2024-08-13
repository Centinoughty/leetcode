// Jewels and stones

#include <stdio.h>

int numJewelsInStones(char* jewels, char* stones) {
    int count = 0;
    int i = 0;
    while (jewels[i] != '\0') {
        int j = 0;
        while (stones[j] != '\0') {
            if (jewels[i] == stones[j]) {
                count ++;
            }

            j ++;
        }

        i ++;
    }

    return count;
}