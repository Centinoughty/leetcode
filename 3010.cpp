// Divide an array into subarrays with minimum cost I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};