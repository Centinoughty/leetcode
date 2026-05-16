// Find minimum in rotated sorted array II
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < n - 1 && nums[l] == nums[n - 1]) {
            l ++;
        }

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[n - 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};
