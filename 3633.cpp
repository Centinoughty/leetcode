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
