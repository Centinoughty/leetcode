// Search in Rotated Sorted Array II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int x = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int y = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(x, y);
    }

private:
    int solve(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i ++) {
            finish1 = min(finish1, start1[i] + dur1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i ++) {
            finish2 = min(finish2, max(finish1, start2[i]) + dur2[i]);
        }

        return finish2;
    }
};
