// Tuple with same product
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> tupleProduct;

    for (int i = 0; i < nums.size() - 1; i ++) {
      for (int j = i + 1; j < nums.size(); j ++) {
        if (tupleProduct.count(nums[i] * nums[j]) == 0) {
          tupleProduct[nums[i] * nums[j]] = 1;
        } else {
          tupleProduct[nums[i] * nums[j]] ++;
        }
      }
    }

    for (auto it = tupleProduct.begin(); it != tupleProduct.end(); it ++) {
      if (it->second > 1) {
        res += comb(it->second, 2) * 8;
      }
    }

    return res;
  }

private:
  long long factorial(int n) {
    long long res = 1;
    for (int i = n; i >= 2; i --) {
      res *= n;
      n --;
    }

    return res;
  }

  int comb(int n, int r) {
    long long res = factorial(n) / (factorial(r) * factorial(n - r));
    return res;
  }
};
