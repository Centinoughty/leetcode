// Minimum Adjascent Swaps to Partition Array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int l1 = 0, l2 = 0;

        int cnt = 0;
        for (const int& num : nums) {
            if (num < a) {
                cnt = (cnt + l1 + l2) % MOD;
            } else if (num <= b) {
                cnt = (cnt + l2) % MOD;
                l1 ++;
            } else {
                l2 ++;
            }
        }

        return cnt;
    }
};
