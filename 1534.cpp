// Count good triplets
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n = arr.size();
    int res = 0;

    for (int i = 0; i < n - 2; i ++) {
      for (int j = i + 1; j < n - 1; j ++) {
        for (int k = j + 1; k < n; k ++) {
          int score = 0;
          if (abs(arr[i] - arr[j]) <= a) {
            score ++;
          }

          if (abs(arr[j] - arr[k]) <= b) {
            score ++;
          }

          if (abs(arr[i] - arr[k]) <= c) {
            score ++;
          }

          if (score == 3) {
            res ++;
          }
        }
      }
    }

    return res;
  }
};
