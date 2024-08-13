// Perfect number
// EASY

#include <stdio.h>
#include <stdbool.h>

bool checkPerfectNumber(int num) {
    int i = 1;
    int sum = 0;
    while (i <= num / i) {
        if (num % i == 0) {
            if (i != num / i) {
                sum += i + num / i;
            } else {
                sum += i;
            }
        }

        i ++;
    }

    return sum - num == num ? true : false;
}