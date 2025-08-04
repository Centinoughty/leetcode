// Koko eating bananas
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN;
        for (const int& pile : piles) {
            r = max(r, pile);
        }

        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            long tempCount = 0;
            for (const int& pile : piles) {
                tempCount += (pile + mid - 1) / mid;
            }

            if (tempCount <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
