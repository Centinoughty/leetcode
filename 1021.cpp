// Remove Outermost Parentheses
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        
        stack<char> st;
        for (const char& c : s) {
            if (c == '(') {
                if (st.size() >= 1) res.push_back(c);
                st.push(c);
            } else {
                st.pop();
                if (!st.empty()) res.push_back(c);
            }
        }

        return res;
    }
};
