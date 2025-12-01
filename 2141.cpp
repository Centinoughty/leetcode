// Maximum running time of N computers
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long sum = accumulate(batteries.begin(), batteries.end(), 0L);

        sort(batteries.begin(), batteries.end());

        while (batteries.back() > sum / n) {
            sum -= batteries.back(), batteries.pop_back();
            -- n;
        }

        return sum / n;
    }
};
