// Palindrome partitioning
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<string> st;

    void dfs(string s, int i) {
        if (i == s.size()) {
            res.push_back(st);
            return;
        }

        for (int j = i; j < s.size(); j ++) {
            if (isPalindrome(s, i, j)) {
                st.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                st.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l ++] != s[r --]) {
                return false;
            }
        }

        return true;
    }
};
