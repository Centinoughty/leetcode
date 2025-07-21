// Climbing stairs
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        long long prev1, prev2;
        long long curr;
        prev2 = 1;
        prev1 = 2;

        for (int i = 2; i < n; i ++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            return curr;
        }
    }
};
