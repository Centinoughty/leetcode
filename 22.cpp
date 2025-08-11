// Generate parentheses
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        genPar(n, 0, 0, "");
        return res;
    }

private:
    vector<string> res;

    void genPar(int n, int op, int cl, string s) {
        if (op == cl && op + cl == n * 2) {
            res.push_back(s);
            return;
        }

        if (op < n) {
            genPar(n, op + 1, cl, s + "(");
        }

        if (op > cl) {
            genPar(n, op, cl + 1, s + ")");
        }
    }
};
