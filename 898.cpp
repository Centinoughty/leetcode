// Bitwise OR of subarrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> st, pre;

        for (const int num : arr) {
            unordered_set<int> temp;
            temp.insert(num);
            for (const int x : pre) {
                temp.insert(x | num);
            }

            for (const int x : temp) {
                st.insert(x);
            }

            pre = temp;
        }

        return st.size();
    }
};

// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });