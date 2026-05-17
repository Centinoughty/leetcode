// Count k-th roots in a range
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int newL = ceil(pow(l, (double)1 / k));
        int newR = floor(pow(r, (double)1 / k));

        if (pow(newL, k) < l) newL ++;
        if (pow(newR, k) > r) newR --;
        if (pow(newR + 1, k) <= r) newR ++;

        cout << newL << " " << newR << endl;

        return max(0, newR - newL + 1);
    }
};
