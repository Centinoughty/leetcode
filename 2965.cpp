// Find missing and repeated values
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    long long n = grid.size();
    long long sum = 0, reqSum = 0;
    long long sqr = 0, reqSqr = 0;

    for (const vector<int> row : grid) {
      for (const int x : row) {
        sum += x;
        sqr += x * x;
      }
    }

    n = n * n;
    reqSum = (n * (n + 1)) / 2;
    reqSqr = (n * (n + 1) * (2 * n + 1)) / 6;

    int x = reqSum - sum;
    int y = reqSqr - sqr;

    int a = (y - x * x) / (2 * x);
    int b = (y + x * x) / (2 * x);

    return {a, b};
  }
};
