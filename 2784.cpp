// Check if array is good
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        int sum = 0, sq = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int x = nums[i];
            sum += x;
            sq += x * x;
        }

        int bal1 = 2 * sum == n * n + 3 * n;
        int bal2 = 6 * sq == (n * (n + 1) * (2 * n + 1)) + 6 * n * n;

        return bal1 && bal2;
    }
};
