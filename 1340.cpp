// Jump game V
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        dp.resize(arr.size(), -1);
        for (int i = 0; i < arr.size(); i ++) {
            dfs(arr, d, i);
        }

        return *max_element(dp.begin(), dp.end());
    }

private:
    vector<int> dp;

    void dfs(vector<int>& arr, int d, int pos) {
        if (dp[pos] != -1) return;

        dp[pos] = 1;

        for (int i = pos - 1; i >= 0 && pos - i <= d && arr[pos] > arr[i]; i --) {
            dfs(arr, d, i);
            dp[pos] = max(dp[pos], dp[i] + 1);
        }

        for (int i = pos + 1; i < arr.size() && i - pos <= d && arr[pos] > arr[i]; i ++) {
            dfs(arr, d, i);
            dp[pos] = max(dp[pos], dp[i] + 1);
        }
    }
};
