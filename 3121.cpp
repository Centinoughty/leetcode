// Count the number of special charecters II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st, vis;

        int cnt = 0;
        for (const char& c : word) {
            if (isLower(c)) {
                st.insert(c);
                if (st.count(c - 'a' + 'A')) {
                    vis.erase(c);
                }
            } else {
                if (st.count(c - 'A' + 'a') && !st.count(c)) {
                    vis.insert(c - 'A' + 'a');
                }

                st.insert(c);
            }
        }

        return vis.size();
    }

private:
    bool isLower(char c) {
        return 'a' <= c && c <= 'z';
    }
};
