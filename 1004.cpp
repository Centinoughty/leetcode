// Max Consecutive Ones III
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        for (const int& num : nums) {
            if (num == 0) {
                k --;
            }

            if (k < 0) {
                if (nums[l] == 0) {
                    k ++;
                }

                l ++;
            }
        }

        return nums.size() - l;
    }
};
