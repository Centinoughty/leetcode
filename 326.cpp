// Power of three
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 1) {
            if (n % 3 == 0) {
                n /= 3;
            } else {
                return false;
            }
        }

        return n == 1;
    }
};

// In O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && !(1162261467 % n);
    }
};

