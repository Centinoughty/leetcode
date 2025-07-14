// Binary number with alternating bits
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n & 1;
        n >>= 1;
        while (n) {
            if ((n & 1) == flag) return false;

            flag ^= 1;
            n >>= 1;
        }

        return true;
    }
};
