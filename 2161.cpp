// Partition array accoring to given pivot
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> res;
    for (const int num : nums) {
      if (num < pivot) {
        res.push_back(num);
      }
    }

    for (const int num : nums) {
      if (num == pivot) {
        res.push_back(num);
      }
    }

    for (const int num : nums) {
      if (num > pivot) {
        res.push_back(num);
      }
    }

    return res;
  }
};

// Two Pointer Approach

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0;
        for (const int& num : nums) {
            if (num < pivot) {
                less ++;
            } else if (num == pivot) {
                equal ++;
            }
        }

        vector<int> res(nums.size(), 0);
        int l = 0, m = less, r = less + equal;
        for (const int& num : nums) {
            if (num < pivot) {
                res[l ++] = num;
            } else if (num == pivot) {
                res[m ++] = num;
            } else {
                res[r ++] = num;
            }
        }

        return res;
    }
};
