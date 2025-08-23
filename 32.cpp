// Longest valid parentheses
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;

        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                    int temp = st.empty() ? -1 : st.top();
                    int curr = i - temp;
                    maxLen = max(maxLen, curr);
                } else {
                    st.push(i);
                }
            }
        }

        return maxLen;
    }
};
