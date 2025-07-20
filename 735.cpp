// Asteroid collision
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (const int asteroid : asteroids) {
            if (asteroid > 0) {
                res.push_back(asteroid);
            } else {
                while (res.size() > 0 && res.back() > 0 && res.back() < -asteroid) {
                    res.pop_back();
                }

                if (res.size()) {
                    if (res.back() == -asteroid) {
                        res.pop_back();
                    } else if (res.back() < 0) {
                        res.push_back(asteroid);
                    }
                } else {
                    res.push_back(asteroid);
                }
            }
        }

        return res;
    }
};
