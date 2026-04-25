// Compare sums of bitonic parts
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long asc = 0, dsc = 0;
        long long prev = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > prev) {
                asc += nums[i];
            } else break;

            prev = nums[i];
        }

        prev = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i --) {
            if (nums[i] > prev) {
                dsc += nums[i];
            } else break;

            prev = nums[i];
        }

        if (asc == dsc) return -1;
        if (asc > dsc) return 0;
        return 1;
    }
};
