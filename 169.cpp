// Majority element
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (const int& num : nums) {
            if (cnt == 0) {
                res = num;
                cnt = 1;
                continue;
            }
            
            if (num == res) {
                cnt ++;
            } else {
                cnt --;
            }
        }

        return res;
    }
};