// Sqrt(x)

#include <stdio.h>

int mySqrt (int x) {
    long long int i = 1;
    while (i * i < x) {
        i ++;
    }

    if (i * i == x) {
        return i;
    } return i - 1;
}


int main () {
    int x;
    scanf("%d", &x);
    printf("%d", mySqrt(x));
}