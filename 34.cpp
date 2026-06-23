// Find First and Last Position of Element in Sorted Array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }

        vector<int> res;
        res.push_back(ans);

        l = 0; r = nums.size() - 1;
        ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }

        res.push_back(ans);

        return res;
    }
};
