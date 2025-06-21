// Longest commmon prefix
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        string res = "";
        int i = 0;
        bool status = true;
        while (status) {
            char c = i < strs[0].length() ? strs[0][i] : ' ';
            for (int j = 1; j < strs.size(); j ++) {
                if (strs[j][i] != c) {
                    status = false;
                    break;
                }
            }

            i ++;
        }

        res = strs[0].substr(0, i - 1);
        return res;
    }
};
