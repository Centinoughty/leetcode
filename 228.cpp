// Summary ranges
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while (i < nums.size()) {
            int j = i;
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                i ++;
            }

            if (i == j) {
                res.push_back(to_string(nums[j]));
            } else {
                res.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
            }

            i ++;
        }

        return res;
    }
};
