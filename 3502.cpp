// Minimum cost to reach every position
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> minCosts(vector<int>& cost) {
    vector<int> res;
    int mini = cost[0];
    for(const int num : cost) {
      mini = min(mini, num);
      res.push_back(mini);
    }

    return res;
  }
};
