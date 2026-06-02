// Find Peak Element
// MEDIUm

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            
            bool left = mid == 0 || nums[mid] > nums[mid - 1];
            bool right = mid == nums.size() - 1 || nums[mid] > nums[mid + 1];

            if (left && right) {
                return mid;
            }

            if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return -1;
    }
};
