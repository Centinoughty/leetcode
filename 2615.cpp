// Sum of distances
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i ++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> res(nums.size());
        for (auto [key, val] : mp) {
            int k = val.size();

            long long total = accumulate(val.begin(), val.end(), 0LL);
            long long prefix = 0;

            for (int i = 0; i < val.size(); i ++) {
                res[val[i]] = total - prefix * 2 + val[i] * (2 * i - val.size());
                prefix += val[i];
            }
        }

        return res;
    }
};
