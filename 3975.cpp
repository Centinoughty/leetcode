// Filter Occupied Intervals
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        mergeIntervals(occupiedIntervals);
        vector<vector<int>> res;

        for (const vector<int> interval : occupiedIntervals) {
            int a = interval[0], b = interval[1];
            if (b < freeStart || a > freeEnd) {
                res.push_back(interval);
            } else {
                if (a < freeStart) {
                    res.push_back({a, freeStart - 1});
                }

                if (b > freeEnd) {
                    res.push_back({freeEnd + 1, b});
                }
            }
        }

        return res;
    }

private:
    void mergeIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int i = 0, j = 1;
        while (j < intervals.size()) {
            int a = intervals[i][0], b = intervals[i][1];
            int c = intervals[j][0], d = intervals[j][1];

            if (b + 1 < c) {
                i ++;
                intervals[i] = intervals[j];
            } else {
                intervals[i][1] = max(b, d);
            }

            j ++;
        }

        intervals.resize(i + 1);
    }
};
