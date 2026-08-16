// Nearest Available Drone
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minDist = INT_MAX, res = -1, i = 0;
        for (vector<int>& drone : drones) {
            int dist = abs(drone[0] - target[0]) + abs(drone[1] - target[1]);
            if (dist <= drone[2]) {
                if (dist < minDist) {
                    minDist = dist;
                    res = i;
                }
            }

            i ++;
        }

        return res;
    }
};
