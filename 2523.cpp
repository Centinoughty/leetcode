// Closest prime numbers in range
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<bool> isPrime = getPrimes(right + 1);
    vector<int> primesInRange;

    for (int i = left; i <= right; i ++) {
      if (isPrime[i]) {
        primesInRange.push_back(i);
      }
    }

    if (primesInRange.size() < 2) {
      return {-1, -1};
    }

    int minDiff = INT_MAX;
    int n1 = -1, n2 = -1;

    for (int i = 1; i < primesInRange.size(); i ++) {
      int diff = primesInRange[i] - primesInRange[i - 1];
      if (diff < minDiff) {
        minDiff = diff;
        n1 = primesInRange[i - 1];
        n2 = primesInRange[i];
      }
    }

    return {n1, n2};
  }

private:
  vector<bool> getPrimes(int n) {
    vector<bool> res(n, true);
    res[0] = false;
    res[1] = false;
    for (int i = 2; i * i < n; i ++) {
      if (res[i]) {
        for (int j = i * i; j < n; j += i) {
          res[j] = false;
        }
      }
    }

    return res;
  }
};
