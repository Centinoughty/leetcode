// Insert interval
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int pos = 0;

    while (pos < intervals.size() && intervals[pos][1] < newInterval[0]) {
      res.push_back(intervals[pos]);
      pos ++;
    }

    while (pos < intervals.size() && intervals[pos][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[pos][0]);
      newInterval[1] = max(newInterval[1], intervals[pos][1]);
      pos ++;
    }

    res.push_back(newInterval);
    while (pos < intervals.size()) {
      res.push_back(intervals[pos]);
      pos ++;
    }

    return res;
  }
};
