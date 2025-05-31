// Rotate image
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    mirror(matrix);
  }

private:
  void transpose(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i ++) {
      for (int j = i + 1; j < matrix[i].size(); j ++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }

  void mirror(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i ++) {
      for (int j = 0; j < matrix[i].size() / 2; j ++) {
        swap(matrix[i][j], matrix[i][matrix[i].size() - j - 1]);
      }
    }
  }
};
