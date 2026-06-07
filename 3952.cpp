// Maximum Total Value of Covered Indices
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        arr = nums;
        t = s;
        memo.assign(nums.size(), vector<long long>(2, -1));

        return solve(nums.size() - 1, 0);
    }

private:
    vector<int> arr;
    string t;
    vector<vector<long long>> memo;
    
    long long solve(int pos, int canFill) {
        if (pos < 0) {
            return canFill ? INT_MIN : 0;
        }

        if (memo[pos][canFill] != -1) {
            return memo[pos][canFill];
        }

        long long total = INT_MIN;
        if (t[pos] == '0') {
            long long gain = canFill ? arr[pos] : 0;
            total = max(total, gain + solve(pos - 1, 0));
        } else {
            if (!canFill) {
                total = max(total, arr[pos] + solve(pos - 1, 0));
            }

            long long gain = canFill ? arr[pos] : 0;
            total = max(total, gain + solve(pos - 1, 1));
        }

        return memo[pos][canFill] = total;
    }
};
