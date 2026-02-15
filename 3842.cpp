// Toggle light bulbs
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> st;
        for (const int bulb : bulbs) {
            if (st.count(bulb) == 0) {
                st.insert(bulb);
            } else {
                st.erase(bulb);
            }
        }

        vector<int> res;
        for (const int x : st) {
            res.push_back(x);
        }

        return res;
    }
};
