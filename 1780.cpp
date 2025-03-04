// Check if number is a sum of powers of three
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkPowersOfThree(int n) {
    while (n) {
      if (n % 3 == 2) {
        return false;
      } else {
        n /= 3;
      }
    }

    return true;
  }
};
