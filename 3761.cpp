// Minimum absolute distance between mirror pairs
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int res = INT_MAX;

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i ++) {
            if (mp.count(nums[i])) {
                res = min(res, i - mp[nums[i]]);
            }

            mp[reverse(nums[i])] = i;
        }

        return res == INT_MAX ? -1 : res;
    }

private:
    int reverse(int n) {
        int res = 0;
        while (n) {
            res *= 10;
            res += n % 10;

            n /= 10;
        }

        return res;
    }
};
