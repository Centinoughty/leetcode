// Number of 1 bits
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count ++;
        }

    return count;
    }
};
