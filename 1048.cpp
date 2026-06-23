// Longest String Chain
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        int n = words.size(), maxVal = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (isValid(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }

private:
    bool isValid(string& s, string& p) {
        int l1 = s.length(), l2 = p.length();
        if (l1 != l2 - 1) return false;

        int i = 0, j = 0;
        bool flag = true;
        while (i < l1 && j < l2) {
            if (s[i] == p[j]) {
                i ++;
                j ++;
            } else {
                if (flag) {
                    j ++;
                    flag = false;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
