// Car fleet
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cmb;
        for (int i = 0; i < position.size(); i ++) {
            cmb.push_back({position[i], speed[i]});
        }

        sort(cmb.rbegin(), cmb.rend());

        int count = 0, i = 0;
        while (i < cmb.size()) {
            int j = i;
            double timeS = getTime(target, cmb[i].first, cmb[i].second);
            while (j < cmb.size() && getTime(target, cmb[j].first, cmb[j].second) <= timeS) {
                j ++;
            }

            count ++;
            i = j;
        }

        return count;
    }

private:
    double getTime(int v, int u, int s) {
        return (double)(v - u)/s;
    }
};
