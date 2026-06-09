// Maximum Total Subarray Value I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        long long res = (long long)(maxi - mini) * k;
        return res;
    }
};
