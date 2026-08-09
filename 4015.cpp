// Weighted Sum of a Tree
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        depth.resize(n, -1);

        for (int i = 0; i < n; i ++) {
            getDepth(parent, i);
        }

        int h = *max_element(depth.begin(), depth.end());

        long long res = 0;
        for (int i = 0; i < n; i ++) {
            res += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return res;
    }

private:
    vector<int> depth;

    int getDepth(vector<int>& parent, int node) {
        if (parent[node] == -1) {
            depth[node] = 1;
            return 1;
        }
        
        if (depth[node] != -1) return depth[node];

        return depth[node] = 1 + getDepth(parent, parent[node]);
    }
};
