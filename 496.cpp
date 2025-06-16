// Next greater element I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i ++) {
            mp[nums2[i]] = i;
        }

        vector<int> res;
        vector<int> ans(nums2.size());
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i --) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(nums2[i]);
        }

        for (const int num : nums1) {
            res.push_back(ans[mp[num]]);
        }

        return res;
    }
};
