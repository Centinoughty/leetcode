// Capacity to Ship Packages Within d Days
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int res;
        while (l <= r) {
            int mid = (l + r) / 2;

            int cnt = 0;
            int curr = 0;
            for (const int& weight : weights) {
                if (curr + weight > mid) {
                    cnt ++;
                    curr = weight;
                } else {
                    curr += weight;
                }
            }

            if (cnt >= days) {
                l = mid + 1;
            } else {
                r = mid - 1;
                res = mid;
            }
        }

        return res;
    }
};
