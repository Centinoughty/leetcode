// Count the number of special charecters I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        int cnt = 0;
        for (const char& c : word) {
            if (isLower(c)) {
                if (!st.count(c) && st.count(c - 'a' + 'A')) cnt ++;
                st.insert(c);
            } else {
                if (!st.count(c) && st.count(c - 'A' + 'a')) cnt ++;
                st.insert(c);
            }
        }

        return cnt;
    }

private:
    bool isLower(char c) {
        return 'a' <= c && c <= 'z';
    }
};
