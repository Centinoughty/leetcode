// Earliest Finish Time for Land and Water Rides I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        int minTime = INT_MAX;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int land = landStartTime[i] + landDuration[i];
                int landWater = max(land, waterStartTime[j]) + waterDuration[j];
                minTime = min(minTime, landWater);

                int water = waterStartTime[j] + waterDuration[j];
                int waterLand = max(water, landStartTime[i]) + landDuration[i];
                minTime = min(minTime, waterLand);
            }
        }

        return minTime;
    }
};

// Linear Time Solution

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
