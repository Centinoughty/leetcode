// Valid elements in an array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i ++) {
            bool validLeft = true, validRight = true;
            for (int j = 0; j < nums.size(); j ++) {
                if (j == i) continue;
                if (j < i && nums[j] >= nums[i]) validLeft = false;
                if (j > i && nums[j] >= nums[i]) validRight = false;
            }

            if (validLeft || validRight) res.push_back(nums[i]);
        }

        return res;
    }
};
