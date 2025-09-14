// Earliest time to finish one task
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini = tasks[0][0] + tasks[0][1];
        for (const auto task : tasks) {
            mini = min(mini, task[0] + task[1]);
        }

        return mini;
    }
};
