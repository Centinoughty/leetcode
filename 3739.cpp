// Count Subarrays with Majority Element II
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(2 * n + 1, 0);
        pre[n] = 1;

        int cnt = 0;
        long long res = 0, curr = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == target) {
                curr += pre[cnt + n];
                cnt ++;
                pre[cnt + n] ++;
            } else {
                cnt --;
                curr -= pre[cnt + n];
                pre[cnt + n] ++;
            }

            res += curr;
        }

        return res;
    }
};
