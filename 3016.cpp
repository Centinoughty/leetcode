// Minimum Number of Pushes to Type Word II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (const int& c : word) {
            freq[c - 'a'] ++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int res = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i ++) {
            res += freq[i] * (i / 8 + 1);
        }

        return res;
    }
};
