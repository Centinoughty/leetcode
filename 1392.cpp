// Longest Happy Prefix
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> pi = generatePi(s);
        
        int n = s.length();
        int l = pi[n];
        return s.substr(n - l);
    }

private:
    vector<int> generatePi(string p) {
        int n = p.length();
        vector<int> pi(n + 1);
        pi[0] = -1;

        for (int i = 0, j = -1; i < n; i ++) {
            while (j >= 0 && p[i] != p[j]) j = pi[j];

            j ++;
            pi[i + 1] = j;
        }

        return pi;
    }
};
