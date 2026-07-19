// Transform Binary String Using Subsequence Sort
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        vector<bool> res;
        int cnt0 = 0, cnt1 = 0;
        for (const char& c : s) {
            if (c == '0') cnt0 ++;
            if (c == '1') cnt1 ++;
        }

        vector<int> pref(n, 0);
        for (int i = 0; i < n; i ++) {
            pref[i] = (s[i] == '1') + (i > 0 ? pref[i - 1] : 0); 
        }

        for (string str : strs) {
            int tmp0 = 0, tmp1 = 0;
            for (const char& c : str) {
                if (c == '0') tmp0 ++;
                if (c == '1') tmp1 ++;
            }

            if (tmp1 > cnt1 || tmp0 > cnt0) {
                res.push_back(false);
                continue;
            }

            for (int i = n - 1; i >= 0; i --) {
                if (str[i] == '?') {
                    if (tmp1 < cnt1) {
                        str[i] = '1';
                        tmp1 ++;
                    } else if (tmp0 < cnt0) {
                        str[i] = '0';
                        tmp0 ++;
                    }
                }
            }

            vector<int> prefTmp(n, 0);
            for (int i = 0; i < n; i ++) {
                prefTmp[i] = (str[i] == '1') + (i > 0 ? prefTmp[i - 1] : 0);
            }

            bool flag = true;
            for (int i = 0; i < n; i ++) {
                if (prefTmp[i] > pref[i]) {
                    flag = false;
                    break;
                }
            }

            res.push_back(flag);
        }

        return res;
    }
};
