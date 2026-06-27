// Maximal Rectangle
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                height[i][j] = matrix[i][j] == '0' ? 0 : (i > 0 ? height[i - 1][j] + 1 : 1);
            }
        }

        int maxArea = 0;
        for (int i = 0; i < m; i ++) {
            vector<int> pse = findPSE(height[i]);
            vector<int> nse = findNSE(height[i]);

            for (int j = 0; j < n; j ++) {
                maxArea = max(maxArea, height[i][j] * (nse[j] - pse[j] - 1));
            }
        }

        return maxArea;
    }

private:
    vector<int> findPSE(vector<int> nums) {
        int n = nums.size();
        vector<int> pse;
        
        stack<int> st;
        for (int i = 0; i < n; i ++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            int top = st.empty() ? -1 : st.top();
            pse.push_back(top);
            st.push(i);
        }

        return pse;
    }

    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        
        stack<int> st;
        for (int i = n - 1; i >= 0; i --) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            int top = st.empty() ? n : st.top();
            nse[i] = top;
            st.push(i);
        }

        return nse;
    }
};
