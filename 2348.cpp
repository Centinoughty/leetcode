// Number of zero-filled subarrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        long long total = 0;
        long long curr = 0;
        while (i < nums.size()) {
            if (nums[i] != 0) {
                total += (curr * (curr + 1)) / 2;
                curr = 0;
            } else {
                curr ++;
            }

            i ++;
        }

        total += (curr * (curr + 1)) / 2;
        return total;
    }
};
