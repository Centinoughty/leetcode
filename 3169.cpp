// Count days without meetings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    vector<vector<int>> res;
    int count = 0;
    sort(meetings.begin(), meetings.end());
    int i = 1, pos = 0;

    while (i < meetings.size()) {
      if (meetings[pos][1] < meetings[i][0]) {
        pos ++;
        meetings[pos] = meetings[i];
      } else {
        meetings[pos][1] = max(meetings[pos][1], meetings[i][1]);
      }

      i ++;
    }

    for (int i = 0; i <= pos; i ++) {
      res.push_back(meetings[i]);
    }

    for (const vector<int> meeting : res) {
      count += meeting[1] - meeting[0] + 1;
    }

    return days - count;
  }
};
