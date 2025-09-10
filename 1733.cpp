// Minimum number of people to reach
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> st;

        for (const auto friendship : friendships) {
            unordered_map<int, int> mp;
            for (int lang : languages[friendship[0] - 1]) {
                mp[lang] = 1;
            }

            bool flag = false;
            for (int lang : languages[friendship[1] - 1]) {
                if (mp[lang]) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                st.insert(friendship[0] - 1);
                st.insert(friendship[1] - 1);
            }
        }

        int maxCnt;
        vector<int> cnt(n);
        for (const int x : st) {
            for (const int lang : languages[x]) {
                cnt[lang - 1] ++;
                maxCnt = max(maxCnt, cnt[lang - 1]);
            }
        }

        return st.size() - maxCnt;
    }
};
