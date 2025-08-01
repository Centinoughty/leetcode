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

// Optimal approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i ++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxProduct = max(maxProduct, max(prefix, suffix));
        }

        return maxProduct;
    }
};
