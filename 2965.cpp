// Find missing and repeated values
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> res;
    long long int sum = 0, requiredSum = 0;
    long long int squared = 0, requiredSquared = 0;
    
    for (const vector<int> row : grid) {
      for (const int x : row) {
        sum += x;
        squared += x * x;
      }
    }

    long long int n = grid.size();
    n = n * n;
    requiredSum = (n * (n + 1)) / 2;
    requiredSquared = (n * (n + 1) * (2 * n + 1)) / 6;

    int x = requiredSum - sum;
    int y = requiredSquared - squared;

    int a = (y - x * x) / (2 * x);
    int b = (x * x + y) / (2 * x);

    res.push_back(a);
    res.push_back(b);
    return res;
  }
};
