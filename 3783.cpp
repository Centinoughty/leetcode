// Mirror distance of an integer
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }

private:
    int reverse(int n) {
        int res = 0;
        while (n) {
            res *= 10;
            res += n % 10;

            n -= n % 10;
            n /= 10;
        }

        return res;
    }
};
