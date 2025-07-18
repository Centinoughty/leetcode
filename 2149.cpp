// Rearrange array elements by sign
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < nums.size() || j < nums.size()) {
            while (i < nums.size() && nums[i] < 0) {
                i ++;
            }

            if (i < nums.size()) res.push_back(nums[i ++]);

            while (j < nums.size() && nums[j] > 0) {
                j ++;
            }

            if (j < nums.size()) res.push_back(nums[j ++]);
        }

        return res;
    }
};
