// Path with minimum effort
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using T = tuple<int, int, int>;

        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!pq.empty()) {
            auto [wg, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1) return wg;

            for (const auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int temp = max(wg, abs(heights[x][y] - heights[nx][ny]));
                    if (dist[nx][ny] > temp) {
                        dist[nx][ny] = temp;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};
