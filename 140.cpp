// Word Break II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string curr = "";
        wordHelper(s, wordDict, curr, 0);
        return res;
    }

private:
    vector<string> res;

    bool wordHelper(string& s, vector<string>& words, string& curr, int pos) {
        if (pos == s.length()) {
            res.push_back(curr);
            return true;
        }

        bool res = false;
        for (const string& word : words) {
            int i = pos, j = 0;
            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    i ++; j ++;
                } else {
                    break;
                }
            }

            if (j == word.length()) {
                string temp = curr;
                if (temp.length() > 0) temp += " ";
                temp += word;
                res |= wordHelper(s, words, temp, pos + word.length());
            }
        }

        return res;
    }
};
