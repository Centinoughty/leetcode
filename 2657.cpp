// Find the prefix common array of two arrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int length = A.size();
    vector<int> res;
    vector<int> hash(length, 0);

    for (int i = 0; i < length; i ++) {
      hash[A[i] - 1] ++;
      hash[B[i] - 1] ++;

      int count = 0;
      for (int j = 0; j < length; j ++) {
        if (hash[j] == 2) {
          count ++;
        }
      }

      res.push_back(count);
    }

    return res;
  }
};

// O(n) solution

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> mp;

        int prefix = 0;
        for (int i = 0; i < A.size(); i ++) {
            mp[A[i]] ++;
            mp[B[i]] ++;

            if (A[i] == B[i]) {
                prefix ++;
                mp[A[i]] = 0;
            } else {
                if (mp[A[i]] == 2) {
                    prefix ++;
                    mp[A[i]] = 0;
                }

                if (mp[B[i]] == 2) {
                    prefix ++;
                    mp[B[i]] = 0;
                }
            }

            res.push_back(prefix);
        }

        return res;
    }
};
