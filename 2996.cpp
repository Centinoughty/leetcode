// Smallest Missing Integer Greater Than Sequential Prefix Sum
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        for (const int& num : nums) {
            st.insert(num);
        }

        int sum = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        while (st.find(sum) != st.end()) {
            sum ++;
        }

        return sum;
    }
};
