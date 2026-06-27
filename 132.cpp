// Palindrome Partitioning II
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        memo.resize(s.length(), -1);
        return cutHelper(s, 0);
    }

private:
    vector<int> memo;

    int cutHelper(string& s, int l) {
        if (l == s.length()) return 0;
        if (memo[l] != -1) return memo[l];

        if (isPalindrome(s, l, s.length() - 1)) return memo[l] = 0;

        int res = s.length() - 1;
        for (int k = l; k < s.length(); k ++) {
            if (isPalindrome(s, l, k)) {
                res = min(res, 1 + cutHelper(s, k + 1));
            }
        }

        return memo[l] = res;
    }

    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i ++] != s[j --]) return false;
        }

        return true;
    }
};
