// Best time to buy and sell stock
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy = 0, sell = 0;
    for (int i = 0; i < prices.size(); i ++) {
      if (prices[i] < prices[buy]) {
        buy = i;
      } else {
        sell = max(sell, prices[i] - prices[buy]);
      }
    }

    return sell;
  }
};
