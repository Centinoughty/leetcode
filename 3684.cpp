// Maximize sum of at mmost k distict elements
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> st;
        for (const int& num : nums) {
            st.insert(num);
        }

        vector<int> res;
        for (auto it = st.rbegin(); it != st.rend() && k; it ++) {
            res.push_back(*it);
            k --;
        }

        return res;
    }
};
