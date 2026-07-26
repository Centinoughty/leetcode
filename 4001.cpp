// Aggregate Two Time Series
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1 = series1.size(), n2 = series2.size();
        vector<vector<int>> res;

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (series1[i][0] < series2[j][0]) {
                series1[i][1] += series2[j][1];
                res.push_back(series1[i ++]);
            } else if (series1[i][0] > series2[j][0]) {
                series2[j][1] += series1[i][1];
                res.push_back(series2[j ++]);
            } else {
                series1[i][1] += series2[j ++][1];
                res.push_back(series1[i ++]);
            }
        }

        while (i < n1) {
            res.push_back(series1[i ++]);
        }

        while (j < n2) {
            res.push_back(series2[j ++]);
        }

        return res;
    }
};
