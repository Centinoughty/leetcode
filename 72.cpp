// Edit Disatnce
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        memo.resize(l1, vector<int>(l2, -1));
        return countHelper(word1, word2, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int countHelper(string s1, string s2, int i, int j) {
        int l1 = s1.length(), l2 = s2.length();
        if (j == s2.length()) return l1 - i;
        if (i == s1.length()) return l2 - j;

        if (memo[i][j] != -1) return memo[i][j];

        int res = INT_MAX;
        if (s1[i] == s2[j]) {
            res = min(res, countHelper(s1, s2, i + 1, j + 1));
        } else {
            res = min(res, 1 + countHelper(s1, s2, i, j + 1));
            res = min(res, 1 + countHelper(s1, s2, i + 1, j));
            res = min(res, 1 + countHelper(s1, s2, i + 1, j + 1));
        }

        return memo[i][j] = res;
    }
};
