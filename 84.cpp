// Largest rectangle in histogram
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> nse(heights.size()), pse(heights.size());
        stack<int> st1, st2;
        for (int i = heights.size() - 1; i >= 0; i --) {
            while (!st1.empty() && heights[st1.top()] >= heights[i]) {
                st1.pop();
            }

            if (st1.empty()) {
                nse[i] = -1;
            } else {
                nse[i] = st1.top();
            }

            st1.push(i);
        }

        for (int i = 0; i < heights.size(); i ++) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }

            if (st2.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st2.top();
            }

            st2.push(i);
        }

        for (int i = 0; i < heights.size(); i ++) {
            int width = 1;
            if (nse[i] == -1) {
                width += heights.size() - i - 1;
            } else {
                width += nse[i] - i - 1;
            }

            if (pse[i] == -1) {
                width += i;
            } else {
                width += i - pse[i] - 1;
            }

            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};

// Single Pass
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;
        for (int i = 0; i < heights.size(); i ++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top();
                nse[top] = i;
                st.pop();
            }

            int top = st.empty() ? -1 : st.top();
            pse[i] = top;
            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top(); st.pop();
            nse[top] = n;
        }

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i ++) {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxArea;
    }
};
