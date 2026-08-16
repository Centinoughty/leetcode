// Maximum Gap Between Stations
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length(), m = station.length();
        vector<int> pref(n), suff(n);
        for (int i = 0, j = 0; i < n; i ++) {
            while (j < m && skill[i] != station[j]) j ++;

            pref[i] = j;
            j ++;
        }

        for (int i = n - 1, j = m - 1; i >= 0; i --) {
            while (j >= 0 && skill[i] != station[j]) j --;

            suff[i] = j;
            j --;
        }

        int res = 0;
        for (int i = 1; i < n; i ++) {
            res = max(res, suff[i] - pref[i - 1]);
        }

        return res;
    }
};
