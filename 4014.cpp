// Minimum Total Price After Applying Discounts
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int m = prices.size(), n = discounts.size();
        
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double res = 0;
        
        int j = n - 1;
        for (int i = m - 1; i >= 0; i --) {
            if (j >= 0) {
                res += (double)(prices[i] * (100 - discounts[j --])) / 100;
            } else {
                res += prices[i];
            }
        }

        return res;
    }
};
