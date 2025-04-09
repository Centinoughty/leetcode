// Top k frequent elements
// MEIDUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (const int num : nums) {
      if (count[num]) {
        count[num]++;
      } else {
        count[num] = 1;
      }
    }

    vector<pair<int, int>> freq(count.begin(), count.end());
    sort(freq.begin(), freq.end(),
      [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
      });

    int n = freq.size();
    vector<int> res;
    for (int i = n - k; i < n; i++) {
      res.push_back(freq[i].first);
    }

    return res;
  }
};
