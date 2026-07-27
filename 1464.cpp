// Maximum Product of Two Elements in an Array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 1;
        if (nums[max2] > nums[max1]) {
            swap(max1, max2);
        }

        for (int i = 2; i < nums.size(); i ++) {
            if (nums[i] > nums[max1]) {
                max2 = max1;
                max1 = i;
            } else if (nums[i] > nums[max2]) {
                max2 = i;
            }
        }

        return (nums[max1] - 1) * (nums[max2] - 1);
    }
};
