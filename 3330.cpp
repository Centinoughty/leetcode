// Find the original string
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        int i = 0;
        while (i < word.length()) {
            int j = i;
            while (j < word.length() && word[i] == word[j]) {
                j ++;
            }

            res += j - i - 1;
            i = j;
        }

        return res;
    }
};
