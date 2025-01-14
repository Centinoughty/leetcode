// Find the prefix common array of two arrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int length = A.size();
    vector<int> res;
    vector<int> hash(length, 0);

    for (int i = 0; i < length; i ++) {
      hash[A[i] - 1] ++;
      hash[B[i] - 1] ++;

      int count = 0;
      for (int j = 0; j < length; j ++) {
        if (hash[j] == 2) {
          count ++;
        }
      }

      res.push_back(count);
    }

    return res;
  }
};
