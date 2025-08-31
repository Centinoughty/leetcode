// Restore finishing order
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        unordered_set<int> st;
        for (const int x : friends) {
            st.insert(x);
        }

        for (const int ord : order) {
            if (st.count(ord)) {
                res.push_back(ord);
            }
        }

        return res;
    }
};
