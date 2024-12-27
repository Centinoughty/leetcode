// Best sightseeing pair
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int max = values[0];
    int res = INT_MIN;

    for (int i = 1; i < values.size(); i ++) {
      if (values[i] - i + max > res) {
        res = values[i] - i + max;
      }

      if (values[i] + i > max) {
        max = values[i] + i;
      }
    }

    return res;
  }
};
