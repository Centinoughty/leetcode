// String to integer (atoi)
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = 0;
        long long res = 0;
        while (i < s.length() && s[i] == ' ') {
            i ++;
        }

        if (i < s.length()) {
            if (s[i] == '-' || s[i] == '+') {
                sign = s[i] == '-' ? -1 : 1;
                i ++;
            }
        }

        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                res = res * 10 + (s[i] - '0');
            } else {
                break;
            }

            if (res * sign <= INT_MIN) {
                return INT_MIN;
            } else if (res * sign >= INT_MAX) {
                return INT_MAX;
            }

            i ++;
        }

        res *= sign;
        return res;
    }
};
