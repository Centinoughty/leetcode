// Number of subarrays with odd sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    
    for (int& num : arr) {
      num %= 2;
    }

    vector<int> dpEven(n), dpOdd(n);

    if (arr[n - 1]) {
      dpOdd[n - 1] = 1;
    } else {
      dpEven[n - 1] = 1;
    }

    for (int i = n - 2; i >= 0; i --) {
      if (arr[i]) {
        dpOdd[i] = (1 + dpEven[i + 1]) % MOD;
        dpEven[i] = dpOdd[i + 1];
      } else {
        dpEven[i] = (1 + dpEven[i + 1]) % MOD;
        dpOdd[i] = dpOdd[i + 1];
      }
    }
    
    int count = 0;
    for (int num : dpOdd) {
      count += num;
      count %= MOD;
    }

    return count;
  }
};
