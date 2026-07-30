// Corporate Flight Bookings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        for (const vector<int>& booking : bookings) {
            int l = booking[0], r = booking[1], w = booking[2];
            diff[l - 1] += w;
            diff[r] -= w;
        }

        for (int i = 1; i <= n; i ++) {
            diff[i] += diff[i - 1];
        }

        diff.resize(n);
        return diff;
    }
};
