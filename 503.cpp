// Next Greater Element II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        
        stack<int> st;
        for (int i = 0; i < n; i ++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        for (int i = 0; i < n && !st.empty(); i ++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }
        }

        for (int i = 0; i < n; i ++) {
            if (nge[i] != -1) {
                nge[i] = nums[nge[i]];
            }
        }

        return nge;
    }
};
