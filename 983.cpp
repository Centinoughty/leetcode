// Minimum cost for tickets
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int res = 0;
    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for (const int day : days) {
      while (!week.empty() && week.front().first + 7 <= day) {
        week.pop();
      }

      while (!month.empty() && month.front().first + 30 <= day) {
        month.pop();
      }

      week.push(make_pair(day, res + costs[1]));
      month.push(make_pair(day, res + costs[2]));
      res = min({res + costs[0], week.front().second, month.front().second});
    }

    return res;
  }
};
