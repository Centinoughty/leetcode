// Find the index of the first occurrence in a string
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = kmp(haystack, needle);
        return res;
    }

private:
    vector<int> generatePi(string s) {
        vector<int> pi(s.length(), 0);
        int i = 0, j = 1;
        while (j < s.length()) {
            if (s[i] == s[j]) {
                pi[j ++] = ++ i;
            } else {
                if (i > 0) {
                    i = pi[i - 1];
                } else {
                    pi[j ++] = 0;
                }
            }
        }

        return pi;
    }

    int kmp(string s1, string s2) {
        vector<int> pi = generatePi(s2);
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i ++;
                j ++;
                if (j == s2.length()) {
                    return i - j;
                }
            } else {
                if (j > 0) {
                    j = pi[j - 1];
                } else {
                    i ++;
                }
            }
        }

        return -1;
    }
};
