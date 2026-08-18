// Find the Largest Almost Missing Integer
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> mp;
        for (const int& num : nums) {
            mp[num] ++;
        }

        if (k == 1) {
            for (int x = 50; x >= 0; x --) {
                if (mp[x] == 1) return x;
            }
        }

        int maxVal = -1;
        if (mp[nums[0]] == 1) maxVal = max(maxVal, nums[0]);
        if (mp[nums[n - 1]] == 1) maxVal = max(maxVal, nums[n - 1]);

        return maxVal;
    }
};
