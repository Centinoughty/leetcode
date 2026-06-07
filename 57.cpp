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

// In memory solution

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int l = 0;
        while (l < intervals.size() && newInterval[0] > intervals[l][0]) {
            l ++;
        }

        if (l > 0) {
            if (intervals[l - 1][1] < newInterval[0]) {
                intervals.insert(intervals.begin() + l, newInterval);
            } else {
                intervals[l - 1][1] = max(intervals[l - 1][1], newInterval[1]);
            }
        } else {
            intervals.insert(intervals.begin(), newInterval);
            l ++;
        }

        l = min(0, l - 1);
        for (int r = l + 1; r < intervals.size(); r ++) {
            int a = intervals[l][0], b = intervals[l][1];
            int c = intervals[r][0], d = intervals[r][1];
            
            if (b < c) {
                intervals[++l] = intervals[r];
            } else {
                intervals[l][1] = max(intervals[l][1], intervals[r][1]);
            }
        }

        intervals.resize(l + 1);
        return intervals;
    }
};
