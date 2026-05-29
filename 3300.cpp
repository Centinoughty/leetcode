// Minimum element after replacement with digit sum
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        for (int& num : nums) {
            int temp = num;
            num = 0;
            while (temp) {
                num += temp % 10;
                temp /= 10;
            }
        }

        return *min_element(nums.begin(), nums.end());
    }
};
