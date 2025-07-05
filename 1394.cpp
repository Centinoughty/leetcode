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

// Optimised space
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> mp(arr.size(), 0);
        for (const int x : arr) {
            if (x <= arr.size()) {
                mp[x - 1] ++;
            }
        }

        for (int i = arr.size() - 1; i >= 0; i --) {
            if (mp[i] == i + 1) {
                return i + 1;
            }
        }

        return -1;
    }
};
