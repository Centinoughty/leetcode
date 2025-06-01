// Majority element II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> hash;
    vector<int> res;
    for (const int num : nums) {
      hash[num] ++;
      if (hash[num] == nums.size() / 3 + 1) {
        res.push_back(num);
      }

      if (res.size() == 2) break;
    }

    return res;
  }
};


// Boyer Moore voting algorithm
class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for (const int num: nums) {
      if (cnt1 == 0 && num != el2) {
        cnt1 = 1;
        el1 = num;
      } else if (cnt2 == 0 && num != el1) {
        cnt2 = 1;
        el2 = num;
      } else if (el1 == num) {
        cnt1 ++;
      } else if (el2 == num) {
        cnt2 ++;
      } else {
        cnt1 --;
        cnt2 --;
      }
    }

    cnt1 = cnt2 = 0;
    for (const int num : nums) {
      if (num == el1) cnt1++;
      if (num == el2) cnt2++;
    }

    int val = nums.size() / 3;
    vector<int> res;
    if (cnt1 > val) {
      res.push_back(el1);
    }

    if (cnt2 > val) {
      res.push_back(el2);
    }

    return res;
  }
};
