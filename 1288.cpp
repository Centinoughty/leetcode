// Remove Covered Intervals
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        });

        int n = intervals.size();
        int maxR = 0, cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (intervals[i][1] > maxR) {
                maxR = intervals[i][1];
            } else {
                cnt ++;
            }
        }

        return n - cnt;
    }
};
