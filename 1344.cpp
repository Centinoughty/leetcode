// Angle Between Hands of a Clock
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        int hourToMin = hour * 60 + minutes;

        double hourAngle = (double)(360 * hourToMin) / (12 * 60);
        double minAngle = (double)(360 * minutes) / 60;

        double ang1 = abs(hourAngle - minAngle);
        double ang2 = 360 - abs(hourAngle - minAngle);

        return min(ang1, ang2);
    }
};
