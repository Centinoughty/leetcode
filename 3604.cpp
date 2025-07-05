// Minimum time to reach destination in directed graph
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> graph(n);
        vector<vector<int>> dalmurecio = edges;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
            graph[u].emplace_back(v, start, end);
        }

        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<int> visited(n, -1);

        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (visited[node] != -1 && time >= visited[node]) continue;

            visited[node] = time;

            if (node == n - 1) return time;

            pq.emplace(time + 1, node);

            for (auto& [ngb, start, end] : graph[node]) {
                if (start <= time && time <= end) {
                    pq.emplace(time + 1, ngb);
                } else if (time < start) {
                    pq.emplace(start + 1, ngb);
                }
            }
        }

        return -1;
    }
};
