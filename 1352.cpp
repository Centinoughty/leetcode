// Product of the last K numbers
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
  vector<int> arr;

  ProductOfNumbers() {}
  
  void add(int num) {
    arr.push_back(num);
  }
  
  int getProduct(int k) {
    int size = arr.size();
    int res = 1;
    for (int i = size - k; i < size; i ++) {
      res *= arr[i];
    }

    return res;
  }
};
