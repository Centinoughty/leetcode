// Number of common factors
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int commonFactors(int a, int b) {
    int count = 0;
    if (a > b) {
      return commonFactors(b, a);
    }

    for (int i = 1; i <= a; i ++) {
      if (a % i == 0 && b% i == 0) {
        count ++;
      }
    }

    return count;
  }
};
