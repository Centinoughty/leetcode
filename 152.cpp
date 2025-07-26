// Maximum product subarray
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            int prod = 1;
            for (int j = i; j < nums.size(); j ++) {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};
