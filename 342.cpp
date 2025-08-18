// Power of four
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPowerOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }

public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        if (isPowerOfTwo(n)) {
            int num = 31 - __builtin_clz(n);
            return num % 2 == 0;
        }

        return false;
    }
};
