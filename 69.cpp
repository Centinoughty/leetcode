// Sqrt(x)
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = 0, r = x / 2;
        while (l <= r) {
            long mid = (l + r) / 2;
            long temp = mid * mid;
            if (temp < x) {
                l = mid + 1;
            } else if (temp > x) {
                r = mid - 1;
            } else {
                return mid;
            }
        }

        return r;
    }
};
