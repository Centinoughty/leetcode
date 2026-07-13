// Sequential Digits
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        generateComb();
        vector<int> res;
        for (const int& x : nums) {
            if (low <= x && x <= high) {
                res.push_back(x);
            }
        }

        return res;
    }

public:
    vector<int> nums;

    void generateComb() {
        for (int i = 1; i < 10; i ++) {
            nums.push_back(i);
        }

        for (int i = 0; i < nums.size(); i ++) {
            int last = nums[i] % 10;
            if (last < 9) nums.push_back(nums[i] * 10 + last + 1);
        }
    }
};
