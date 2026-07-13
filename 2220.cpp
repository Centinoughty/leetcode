// Minimum Bit Flips to Convert Number
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        while (start && goal) {
            if ((start & 1) != (goal & 1)) count ++;
            start >>= 1;
            goal >>= 1;
        }

        while (start) {
            if (start & 1) count ++;
            start >>= 1;
        }

        while (goal) {
            if (goal & 1) count ++;
            goal >>= 1;
        }

        return count;
    }
};

// XOR
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorRes = start ^ goal;
        
        int count = 0;
        while (xorRes) {
            if (xorRes & 1) count ++;
            xorRes >>= 1;
        }

        return count;
    }
};
