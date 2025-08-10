// Maximum k to sort a permutation
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX;
        for (int i = 0; i < nums.size(); i ++) {
            if (i == nums[i]) continue;

            k = k & i & nums[i];
        }

        return k == INT_MAX ? 0 : k;
    }
};
