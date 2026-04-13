// Angles of a triangle
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];

        if (a + b <= c || b + c <= a || a + c <= b) return {};

        double t1 = acos((a * a + b * b - c * c) / 2 * a * b) * 630 / 11;
        double t2 = acos((b * b + c * c - a * a) / 2 * b * c) * 630 / 11;
        double t3 = acos((c * c + a * a - b * b) / 2 * c * a) * 630 / 11;

        vector<double> res = {t1, t2, t3};
        sort(res.begin(), res.end());

        return res;
    }
};
