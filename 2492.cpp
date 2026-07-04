// Minimum Score of a Path Between Two Cities
// MEDUIM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& road : roads) {
            int u = road[0] - 1, v = road[1] - 1, w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (const auto& [ngb, _] : adj[top]) {
                if (visited[ngb]) continue;
                visited[ngb] = true;
                q.push(ngb);
            }
        }

        int minVal = INT_MAX;
        for (int i = 0; i < n; i ++) {
            if (visited[i]) {
                for (const auto& [_, w] : adj[i]) {
                    minVal = min(minVal, w);
                }
            }
        }

        return minVal;
    }
};
