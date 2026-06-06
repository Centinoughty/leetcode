// Minimum Energy to Maintain Brightness
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        mergeIntervals(intervals);

        int cntActiveBulbs = (brightness + 3 - 1) / 3;

        long long energy = 0;
        for (const vector<int>& interval : intervals) {
            // cout << interval[0] << " " << interval[1] << endl;
            energy += (long long)(interval[1] - interval[0] + 1) * cntActiveBulbs;
        }

        return energy;
    }

private:
    void mergeIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int l = 0;
        for (int r = 1; r < intervals.size(); r ++) {
            int a = intervals[l][0], b = intervals[l][1];
            int c = intervals[r][0], d = intervals[r][1];

            if (b < c) {
                intervals[++l] = intervals[r];
            } else {
                intervals[l][0] = a;
                intervals[l][1] = max(b, d);
            }
        }

        intervals.resize(l + 1);
    }
};
