// Furthest point from origin
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        for (const char move : moves) {
            if (move == 'L') l ++;
            if (move == 'R') r ++;
        }

        return abs(l - r) + moves.length() - l - r;
    }
};
