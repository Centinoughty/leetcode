// Sum of Subarray Ranges
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i ++) {
            int maxVal = nums[i], minVal = nums[i];
            for (int j = i; j < n; j ++) {
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);
                res += maxVal - minVal;
            }
        }

        return res;
    }
};

// O(n)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n, -1), nse(n, n);
        vector<int> pge(n, -1), nge(n, n);

        stack<int> st;
        for (int i = 0; i < n; i ++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                nse[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i --) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                pse[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i --) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                pge[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i ++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        long long small = 0;
        for (int i = 0; i < n; i ++) {
            int l = i - pse[i];
            int r = nse[i] - i;
            small += 1LL * l * r * nums[i];
        }

        long long large = 0;
        for (int i = 0; i < n; i ++) {
            int l = i - pge[i];
            int r = nge[i] - i;
            large += 1LL * l * r * nums[i];
        }

        return large - small;
    }
};
