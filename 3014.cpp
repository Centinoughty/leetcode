// Minimum Number of Pushes to Type Word I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, unordered_map<char, int>> mp;
        unordered_map<char, int> grp;

        int cnt = 2, res = 0;
        for (const char& c : word) {
            if (grp.find(c) == grp.end()) {
                grp[c] = cnt;
                mp[cnt][c] = mp[cnt].size() + 1;

                cnt ++;
                if (cnt == 10) cnt = 2;
            }

            res += mp[grp[c]][c];
        }

        return res;
    }
};
