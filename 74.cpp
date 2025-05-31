// Search a 2D matrix
// MEDIUM

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;

    while (l <= r) {
      int mid = (l + r) / 2;
      int x = mid / n;
      int y = mid % n;
      if (matrix[x][y] > target) {
        r = mid - 1;
      } else if (matrix[x][y] < target) {
        l = mid + 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
