// Rabbits in forest
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numRabbits(vector<int>& answers) {
    int count = 0;
    unordered_map<int, int> hash;

    for (const int answer : answers) {
      hash[answer] ++;
    }

    for (pair<int, int> x : hash) {
      count += ceil((double)x.second / (x.first + 1)) * (x.first + 1);
    }

    return count;
  }
};
