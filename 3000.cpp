// Maximum area of longest rectangle
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long findDgSqr(vector<int>& dimension) {
        long temp;
        temp = (dimension[0] * dimension[0] + dimension[1] * dimension[1]);
        return temp;
    }

public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        long maxDg = 0;
        for (auto& dimension : dimensions) {
            long dg = findDgSqr(dimension);
            int temp = dimension[0] * dimension[1];
            if (dg > maxDg || (dg == maxDg && temp > maxArea)) {
                maxDg = dg;
                maxArea = temp;
            }
        }

        return maxArea;
    }
};
