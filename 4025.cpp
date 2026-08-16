// Minimize the Maximum Waiting Time at Synchronized Traffic Lights
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxPenalty = 0;

        int maxLight = *max_element(lights.begin(), lights.end());
        for (const int& x : arrivalTime) {
            int r = x % period;
            if (r >= maxLight) {
                maxPenalty = max(maxPenalty, period - r);
            }
        }

        return maxPenalty;
    }
};
