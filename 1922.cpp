// Count good numbers
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countGoodNumbers(long long n) {
    return power(20, n / 2) * (n % 2 ? 5 : 1) % LARGE;
  }

private:
  static const int LARGE = 1000000007;

  long long power(long long x, long long n) {
    if (n == 0) {
      return 1;
    }

    if (n % 2) {
      return x * power(x, n - 1) % LARGE;
    }

    return power(x * x % LARGE, n / 2);
  }
};
