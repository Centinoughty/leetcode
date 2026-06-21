// Maximum Manhattan Distance after all moves
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int u = 0, d = 0, l = 0, r = 0;
        int temp = 0;
        for (const char& c : moves) {
            if (c == 'U') u ++;
            if (c == 'D') d ++;
            if (c == 'L') l ++;
            if (c == 'R') r ++;
            if (c == '_') temp ++;
        }

        return abs(u - d) + abs(l - r) + temp;
    }
};
