// Check if grid can be cut into sections
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<vector<int>> x;
    vector<vector<int>> y;
    
    for (const vector<int> rectangle : rectangles) {
      vector<int> temp1, temp2;
      temp1.push_back(rectangle[1]);
      temp1.push_back(rectangle[3]);
      temp2.push_back(rectangle[0]);
      temp2.push_back(rectangle[2]);
      x.push_back(temp2);
      y.push_back(temp1);
    }

    x = mergeIntervals(x);
    y = mergeIntervals(y);
    return x.size() >= 3 || y.size() >= 3;
  }

private:
  vector<vector<int>> mergeIntervals(vector<vector<int>>& pairs) {
    vector<vector<int>>res;
    sort(pairs.begin(), pairs.end());
    int i = 0;

    while (i < pairs.size()) {
      if (res.empty() || res.back()[1] <= pairs[i][0]) {
        res.push_back(pairs[i]);
      } else {
        res.back()[1] = max(res.back()[1], pairs[i][1]);
      }

      i ++;
    }

    return res;
  }
};