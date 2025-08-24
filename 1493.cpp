// Longest subarray of 1's after deleting one element
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0, zeroCnt = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j ++) {
            if (nums[j] == 0) {
                zeroCnt ++;
            }

            while (zeroCnt > 1) {
                if (nums[i] == 0) {
                    zeroCnt --;
                }

                i ++;
            }

            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};
