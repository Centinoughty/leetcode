// Single element in a sorted array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i] == nums[i + 1]) {
                i ++;
            } else {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};

// XOR Approack
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (const int num : nums) {
            res ^= num;
        }

        return res;
    }
};

// Binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return nums[l];
    }
};
