// Minimum Moves to Reach Target Score
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while (target > 1) {
            if (target % 2) {
                target --;
                count ++;
            } else {
                if (maxDoubles) {
                    maxDoubles --;
                    target /= 2;
                    count ++;
                } else {
                    count += target - 1;
                    target = 1;
                }
            }
        }

        return count;
    }
};
