// Find the Highest Altitude
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0, alt = 0;
        for (const int& x : gain) {
            alt += x;
            maxAlt = max(maxAlt, alt);
        }

        return maxAlt;
    }
};
