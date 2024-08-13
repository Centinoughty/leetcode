// Sum multiples
// EASY

#include <stdio.h>

int sumOfMultiples(int n){
    int ans = 0;
    for (int i = 3; i <= n; i ++) {
        if (!(i % 3) || !(i % 5) || !(i % 7)) {
            ans += i;
        }
    }

    return ans;
}