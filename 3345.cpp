// Smallest Divisible Digit Product I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int x = n; x < n + 10; x ++) {
            int temp = 1, curr = x;
            while (curr) {
                temp *= (curr % 10);
                curr /= 10;
            }

            if (temp % t == 0) {
                return x;
            }
        }

        return n;
    }
};
