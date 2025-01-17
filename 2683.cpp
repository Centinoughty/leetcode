// Neighboring bitwise xor
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool doesValidArrayExist(vector<int>& derived) {
    int ans = 0;
    for (const int x : derived) {
      ans ^= x;
    }

    return ans == 0;
  }
};
