// Number of Unique XOR Triplets II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> newSt;
        for (const int& x : st) {
            for (const int& num : nums) {
                newSt.insert(x ^ num);
            }
        }

        return newSt.size();
    }
};
