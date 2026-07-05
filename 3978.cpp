// Unique Middle Element
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        unordered_map<int, int> mp;
        for (const int& num : nums) {
            mp[num] ++;
        }

        return mp[nums[mid]] == 1;
    }
};
