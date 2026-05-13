// Minimum moves to make array complementary
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();

        for (int i = 0; i < n / 2; i ++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int curr = 0, res = n;
        for (int c = 2; c <= 2 * limit; c ++) {
            curr += diff[c];
            res = min(res, curr);
        }

        return res;
    }
};
