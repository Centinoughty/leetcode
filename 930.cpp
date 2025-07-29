// Binary subarrays with sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return maximumSum(nums, goal) - maximumSum(nums, goal - 1);
    }

private:
    int maximumSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int l = 0, r = 0;
        int count = 0, sum = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l ++];
            }

            count += (r - l + 1);
            r ++;
        }

        return count;
    }
};
