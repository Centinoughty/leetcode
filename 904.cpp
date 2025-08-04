// Fruits into baskets
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, maxSize = 0;;
        unordered_map<int, int> mp;
        for (int r = 0; r < fruits.size(); r ++) {
            mp[fruits[r]] ++;

            while (mp.size() > 2) {
                mp[fruits[l]] --;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }

                l ++;
            }

            maxSize = max(maxSize, r - l + 1);
        }

        return maxSize;
    }
};
