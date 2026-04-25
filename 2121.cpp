// Intervals between identical elements
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i ++) {
            mp[arr[i]].push_back(i);
        }

        vector<long long> res(arr.size());
        for (auto& [key, val] : mp) {
            long long total = accumulate(val.begin(), val.end(), 0LL);
            long long prefix = 0;

            for (int i = 0; i < val.size(); i ++) {
                res[val[i]] = total - prefix * 2 + val[i] * (2 * i  - val.size());
                prefix += val[i];
            }
        }

        return res;
    }
};
