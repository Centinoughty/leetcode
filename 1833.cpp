// Maximum Ice Cream Bars
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0, i = 0;
        while (coins && i < costs.size()) {
            if (costs[i] <= coins) {
                coins -= costs[i ++];
                count ++;
            } else {
                break;
            }
        }

        return count;
    }
};
