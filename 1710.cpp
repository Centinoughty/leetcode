// Maximum Units on a Truck
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int cnt = 0, maxUnits = 0;
        for (int i = 0; i < boxTypes.size() && cnt < truckSize; i ++) {
            int chosen = cnt + boxTypes[i][0] > truckSize ? truckSize - cnt : boxTypes[i][0];
            cnt += chosen;
            maxUnits += chosen * boxTypes[i][1];
        }

        return maxUnits;
    }
};
