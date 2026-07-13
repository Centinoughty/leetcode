// Divide Two Integers
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        bool flag = true;
        if (dividend <= 0) flag = !flag;
        if (divisor < 0) flag = !flag;

        long res = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt ++;
            }

            res += (1 << cnt);
            n -= (d << cnt);
        }

        if (res == (1 << 31) && flag) return INT_MAX;
        if (res == (1 << 31) && !flag) return INT_MIN;

        return flag ? res : -res;
    }
};
