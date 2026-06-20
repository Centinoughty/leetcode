// Distinct Subsequences
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        memo.resize(l1, vector<int>(l2, -1));;
        return countHelper(s, t, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int countHelper(string& s, string& t, int i, int j) {
        int l1 = s.length(), l2 = t.length();
        if (i == l1) return (j == l2);
        if (j == l2) return 1;

        if (memo[i][j] != -1) return memo[i][j];
    
        int res = 0;
        if (s[i] == t[j]) {
            res += countHelper(s, t, i + 1, j + 1);
        }

        res += countHelper(s, t, i + 1, j);
        return memo[i][j] = res;
    }
};

// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i <= l1; i ++) {
            dp[i][l2] = 1;
        }

        for (int i = l1 - 1; i >= 0; i --) {
            for (int j = l2 - 1; j >= 0; j --) {
                long long res = 0;
                if (s[i] == t[j]) {
                    res += dp[i + 1][j + 1];
                }

                res += dp[i + 1][j];
                dp[i][j] = res;
            }
        }

        return dp[0][0];
    }
};
