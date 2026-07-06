// Subsequence After One Replacement
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int l1 = s.length(), l2 = t.length();

        int i = 0, j = 0;
        int last = 0;
        bool used = false;
        while (i < l1 && j < l2) {
            if (s[i] == t[j]) {
                i ++;
                j ++;
            } else {
                if (used) {
                    if (s[last] == t[j]) {
                        used = false;
                        i = last;
                        i ++;
                        j ++;
                    } else {
                        j ++;
                    }
                } else {
                    used = true;
                    last = i;
                    i ++;
                    j ++;
                }
            }
        }

        return i == l1;
    }
};
