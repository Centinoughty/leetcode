// Maximum subarray
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for (const int num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};