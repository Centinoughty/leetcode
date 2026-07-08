// Rank Transform of an Array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i ++) {
            nums.push_back({arr[i], i});
        }

        vector<int> res(n, 0);

        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i ++) {
            if (i == 0 || nums[i].first != nums[i - 1].first) cnt ++;
            res[nums[i].second] = cnt;
        }

        return res;
    }
};
