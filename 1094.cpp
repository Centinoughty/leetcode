// Car Pooling
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxTo = trips[0][2];
        for (int i = 1; i < trips.size(); i ++) {
            maxTo = max(maxTo, trips[i][2]);
        }

        vector<int> diff(maxTo + 1, 0);
        for (const vector<int>& trip : trips) {
            int f = trip[1], t = trip[2], c = trip[0];
            diff[f] += c;
            diff[t] -= c;
        }

        for (int i = 1; i < maxTo + 1; i ++) {
            diff[i] += diff[i - 1];
        }

        for (const int& x : diff) {
            if (x > capacity) return false;
        }

        return true;
    }
};
