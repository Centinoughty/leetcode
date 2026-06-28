// Minimum Time to Reach Target With Limited Power
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(power + 1, LLONG_MAX));

        pq.push({{0, -power}, source});
        dist[source][power] = 0;

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            auto [t, p] = top.first;
            int node = top.second;

            if (-p < cost[node]) continue;

            for (const auto& [ngb, w] : adj[node]) {
                int nP = -p - cost[node];
                long long nT = (long long)t + w;
                if (nT < dist[ngb][nP]) {
                    dist[ngb][nP] = nT;
                    pq.push({{nT, -nP}, ngb});
                }
            }
        }

        long long minTime = LLONG_MAX, maxPower = -1;
        for (int p = 0; p <= power; p ++) {
            if (dist[target][p] < minTime) {
                minTime = dist[target][p];
                maxPower = p;
            } else if (dist[target][p] == minTime) {
                maxPower = max(maxPower, (long long)p);
            }
        }

        if (minTime == LLONG_MAX) {
            return {-1, -1};
        }

        return {minTime, maxPower};
    }
};
