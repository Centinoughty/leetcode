// XOR after range multiplication queries I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;

        for (const vector<int> query : queries) {
            for (int i = query[0]; i <= query[1]; i += query[2]) {
                nums[i] = (1LL * nums[i] * query[3]) % MOD;
            }
        }

        int res = 0;
        for (const int num : nums) {
            res ^= num;
        }

        return res;
    }
};
