// Seperate the digits in an array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            stack<int> st;
            while (num) {
                st.push(num % 10);
                num /= 10;
            }

            while (!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }
        }

        return res;
    }
};
