// Minimum distance between three equal elements I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX;

        unordered_map<int, queue<int>> mp;
        for (int i = 0; i < nums.size(); i ++) {
            if (mp.count(nums[i])) {
                if (mp[nums[i]].size() == 3) mp[nums[i]].pop();
            }

            mp[nums[i]].push(i);
            if (mp[nums[i]].size() == 3) {
                int acc = 0;
                int x = mp[nums[i]].front(); mp[nums[i]].pop();
                int y = mp[nums[i]].front(); mp[nums[i]].pop();
                int z = mp[nums[i]].front(); mp[nums[i]].pop();

                mp[nums[i]].push(x); mp[nums[i]].push(y); mp[nums[i]].push(z);

                res = min(res, 2 * (z - x));
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
