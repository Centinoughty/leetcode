// Find a Peak Element II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int curr = 0;
            for (int j = 1; j < n; j ++) {
                if (mat[mid][j] > mat[mid][curr]) {
                    curr = j;
                }
            }

            bool top = mid == 0 || mat[mid][curr] > mat[mid - 1][curr];
            bool bottom = mid == m - 1 || mat[mid][curr] > mat[mid + 1][curr];

            if (top && bottom) {
                return { mid, curr };
            }

            if (!top) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return {};
    }
};
