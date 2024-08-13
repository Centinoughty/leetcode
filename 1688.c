// Count of matches in tournament
// EASY

#include <stdio.h>

int numberOfMatches(int n){
    int matches = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            matches += n / 2;
        } else {
            matches += (n + 1) / 2;
        }
        n /= 2;
    }

    return matches;
}