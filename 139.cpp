// Word Break
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.length(), -1);
        return wordHelper(s, wordDict, 0);
    }

private:
    vector<int> memo;

    bool wordHelper(string& s, vector<string>& words, int pos) {
        if (pos >= s.length()) return true;

        if (memo[pos] != -1) return memo[pos];

        bool res = false;
        for (const string word : words) {
            int i = pos, j = 0;
            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    i ++; j ++;
                } else {
                    break;
                }
            }

            if (j == word.length()) {
                res |= wordHelper(s, words, pos + word.length());
            }
        }

        return memo[pos] = res;
    }
};
