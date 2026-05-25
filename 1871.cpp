// Jump game VII
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;

        int cnt = 0;
        for (int i = 1; i < n; i ++) {
            if (i >= minJump && dp[i - minJump]) cnt ++;

            if (i > maxJump && dp[i - maxJump - 1]) cnt --;

            if (cnt > 0 && s[i] == '0') dp[i] = true;
        }

        return dp.back();
    }
};
