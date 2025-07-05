// Find lucky number in an array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> mp(501, 0);
        for (const int x : arr) {
            mp[x] ++;
        }

        for (int i = arr.size(); i > 0; i --) {
            if (mp[i] == i) {
                return i;
            }
        }

        return -1;
    }
};
