// Left and Right Sum Differences
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1; i < n; i ++) {
            left[i] = left[i - 1] + nums[i - 1];
            right[n - i - 1] = right[n - i] + nums[n - i];
        }

        for (int i = 0; i < n; i ++) {
            res.push_back(abs(left[i] - right[i]));
        }

        return res;
    }
};
