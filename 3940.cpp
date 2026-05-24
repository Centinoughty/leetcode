// Limit occurrences in sorted array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i = 1, j = 1;
        int cnt = 1;

        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                if (cnt < k) {
                    cnt ++;
                    nums[j ++] = nums[i ++];
                } else {
                    i ++;
                }
            }

            if (i < nums.size()) {
                nums[j ++] = nums[i ++];
            }

            cnt = 1;
        }

        nums.resize(j);
        return nums;
    }
};
