// Minimum Operations to Transform Binary String
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {
        int l = s1.length();
        int ops = 0;
        for (int i = 0; i < l; i ++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == '0') {
                    s1[i] = '1';
                    ops ++;
                } else {
                    if (i + 1 < l && s1[i + 1] == '1') {
                        s1[i] = s1[i + 1] = '0';
                        ops ++;
                    } else if (i + 1 < l && s1[i + 1] == '0') {
                        s1[i] = s1[i + 1] = '0';
                        ops += 2;
                    } else if (i - 1 >= 0) {
                        ops += 2;
                        s1[i] = '0';
                    }
                }
            }
        }

        if (s1 == s2) return ops;
        return -1;
    }
};
