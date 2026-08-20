// Distribute Elements Into Two Arrays I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        
        int pos = 0;
        if (pos < n) arr1.push_back(nums[pos ++]);
        if (pos < n) arr2.push_back(nums[pos ++]);

        bool flag = false;
        while (pos < n) {
            if (arr1.back() > arr2.back()) {
                if (pos < n) arr1.push_back(nums[pos ++]);
            } else {
                if (pos < n) arr2.push_back(nums[pos ++]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
