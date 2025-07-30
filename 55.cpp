// Jump game
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            if (i > maxJump) return false;

            maxJump = max(maxJump, i + nums[i]);
            if (maxJump >= nums.size() - 1) {
                return true;
            }
        }

        return false;
    }
};
