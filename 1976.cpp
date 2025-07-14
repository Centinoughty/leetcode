// Number of ways to arrive at destination
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> ways(n, 0), dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [wg, top] = pq.top();
            pq.pop();
            if (wg > dist[top]) continue;

            for (const auto& [ngb, w] : graph[top]) {
                if (dist[ngb] > wg + w) {
                    dist[ngb] = wg + w;
                    ways[ngb] = ways[top];
                    pq.push({dist[ngb], ngb});
                } else if (dist[ngb] == wg + w) {
                    ways[ngb] += ways[top];
                    ways[ngb] %= 1000000007;
                }
            }
        }

        return ways[n - 1] % 1000000007;
    }
};
