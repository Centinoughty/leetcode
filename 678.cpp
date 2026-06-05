// Valid Parentheses String
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        t = s;
        memo.assign(s.length(), vector<int>(s.length(), -1));
        return solve(0, 0);
    }

private:
    string t;
    vector<vector<int>> memo;

    bool solve(int pos, int count) {
        if (pos == t.size()) return count == 0;

        if (memo[pos][count] != -1) return memo[pos][count];

        bool isValid = false;
        if (t[pos] == '*') {
            isValid |= solve(pos + 1, count + 1);
            if (count) isValid |= solve(pos + 1, count - 1);
            isValid |= solve(pos + 1, count);
        } else {
            if (t[pos] == '(') {
                isValid |= solve(pos + 1, count + 1);
            } else if (count) {
                isValid |= solve(pos + 1, count - 1);
            }
        }

        return memo[pos][count] = isValid;
    }
};
