// Maximum Product of Three Numbers
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int last = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int first = nums[0] * nums[1] * nums[n - 1];

        return max(last, first);
    }
};
