// Destroying asteroids
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long curr = mass;

        for (const int asteroid : asteroids) {
            if (curr < asteroid) {
                return false;
            }

            curr += asteroid;
        }

        return true;
    }
};
