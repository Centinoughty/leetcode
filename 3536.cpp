// Maximum Product of Two Digits
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0;
        while (n) {
            int dig = n % 10;
            if (dig > a) {
                b = a;
                a = dig;
            } else if (dig > b) {
                b = dig;
            }

            n /= 10;
        }

        return a * b;
    }
};
