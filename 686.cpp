// Repeated string match
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string res = a;
        int n1 = a.length(), n2 = b.length();
        int times = n2 / n1;
        int cnt = 1;
        for (int i = 0; i < times - 1; i ++) {
            res += a;
            cnt ++;
        }

        for (int i = 0; i <= times + 2; i ++) {
            if (kmp(res, b) != -1) {
                return cnt;
            } else {
                res += a;
                cnt ++;
            }
        }

        return -1;
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
