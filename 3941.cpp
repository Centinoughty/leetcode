// Password strength
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        int cnt = 0;
        unordered_set<int> st;
        for (const char c : password) {
            if (st.count(c)) continue;
            st.insert(c);

            if (isLower(c)) cnt ++;
            if (isUpper(c)) cnt += 2;
            if (isDigit(c)) cnt += 3;
            if (isSymbol(c)) cnt += 5;
        }

        return cnt;
    }

private:
    bool isLower(char c) {
        if ('a' <= c && c <= 'z') return true;
        return false;
    }

    bool isUpper(char c) {
        if ('A' <= c && c <= 'Z') return true;
        return false;
    }

    bool isDigit(char c) {
        if ('0' <= c && c <= '9') return true;
        return false;
    }

    bool isSymbol(char c) {
        unordered_set<char> st = { '!', '@', '#', '$' };
        return st.count(c);
    }
};
