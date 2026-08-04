// Find Missing Elements
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> res;
        for (int i = 1; i < nums.size(); i ++) {
            int prev = nums[i - 1];
            while (nums[i] - prev > 1) {
                res.push_back(prev + 1);

                prev ++;
            }
        }

        return res;
    }
};
