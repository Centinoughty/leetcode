// Maximise Sum of Device Ratings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        if (units[0].size() == 1) {
            long long tempSum = 0;
            for (int i = 0; i < units.size(); i ++) {
                tempSum += units[i][0];
            }

            return tempSum;
        }
        
        long long sum = 0;

        int fMin = INT_MAX;
        int sMin = INT_MAX;
        for (vector<int>& unit : units) {
            sort(unit.begin(), unit.end());

            fMin = min(fMin, unit[0]);
            sMin = min(sMin, unit[1]);
            sum += unit[1];
        }

        return sum + fMin - sMin;
    }
};
