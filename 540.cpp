// Single element in a sorted array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i] == nums[i + 1]) {
                i ++;
            } else {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};
