// Ugly number II
// MEDIUM

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> arr{1};
    int i2 = 0, i3 = 0, i5 = 0;

    while (arr.size() < n) {
      int n2 = arr[i2] * 2;
      int n3 = arr[i3] * 3;
      int n5 = arr[i5] * 5;
      int temp = min({n2, n3, n5});
      if (temp == n2) {
        i2 ++;
      }
      if (temp == n3) {
        i3 ++;
      }
      if (temp == n5) {
        i5 ++;
      }

      arr.push_back(temp);
    }

    return arr.back();
  }
};
