// Sum of Subarray Minimums
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long res = 0;
        for (int i = 0; i < n; i ++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            res = (res + ((((left * right) % MOD) * arr[i]) % MOD)) % MOD;
        }

        return res % MOD;
    }

private:
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        
        stack<int> st;
        for (int i = 0; i < n; i ++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nse[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return nse;
    }

    vector<int> findPSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n, -1);
        
        stack<int> st;
        for (int i = n - 1; i >= 0; i --) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                pse[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return pse;
    }
};
