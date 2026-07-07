// Concatenate Non-Zero Digits and Multiply by Sum I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0, num = 0;

        string s = to_string(n);
        for (const char& c : s) {
            int temp = (c - '0');
            if (temp != 0) {
                sum += temp;
                num *= 10;
                num += temp;
            }
        }

        return 1LL * sum * num;
    }
};
