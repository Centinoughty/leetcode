// Find the length of the longest common prefix
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for (int num : arr1) {
            while (st.find(num) == st.end() && num) {
                st.insert(num);
                num /= 10;
            }
        }

        int maxLen = 0;
        for (int num : arr2) {
            while (st.find(num) == st.end() && num) {
                num /= 10;
            }

            if (num) {
                maxLen = max(maxLen, (int)log10(num) + 1);
            }
        }

        return maxLen;
    }
};
