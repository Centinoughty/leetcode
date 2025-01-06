// Minimum number of operations to move all balls to each box
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> minOperations(string boxes) {
    vector<int> res (boxes.size(), 0);

    for (int i = 0; i < boxes.size(); i++) {
      for (int j = 0; j < boxes.size(); j++) {
        if (i != j) {
          res[i] += boxes[j] == '1' ? abs(i - j) : 0;
        }
      }
    }

    return res;
  }
};
