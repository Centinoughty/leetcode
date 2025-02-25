// Maximum sum with at most k elements
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    vector<int> temp;
    for (int i = 0; i < grid.size(); i ++) {
      vector<int> row = grid[i];
      sort(row.rbegin(), row.rend());

      for (int j = 0; j < limits[i]; j ++) {
        temp.push_back(row[j]);
      }
    }

    long long int res = 0;
    sort(temp.rbegin(), temp.rend());
    for (int i = 0; i < k; i ++) {
      res += temp[i];
    }

    return res;
  }
};
