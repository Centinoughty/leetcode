// Palindrome number

#include <stdio.h>
#include <stdbool.h>


bool isPalindrome(int x) {
    long long int reverseNum = 0;
    int copy = x;
    if (x < 0) {
        return false;
    } else {
        while (copy > 0) {
            reverseNum = reverseNum * 10 + copy % 10;
            copy /= 10;
        }
    }

    if (reverseNum == x) {
        return true;
    } else {
        return false;
    }
}