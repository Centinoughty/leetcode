// Merge intervals
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    int l = 0, r = 1;
    while (r < intervals.size()) {
      if (intervals[l][1] >= intervals[r][0]) {
        intervals[l][1] = max(intervals[l][1], intervals[r][1]);
        r ++;
     } else {
        res.push_back(intervals[l]);
        l = r;
        r = l + 1;
      }
    }

    res.push_back(intervals[l]);
    return res;
  }
};
