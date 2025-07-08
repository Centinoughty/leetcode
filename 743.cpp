// Network delay time
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int> x : times) {
            int u = x[0], v = x[1], w = x[2];
            graph[u - 1].push_back({v - 1, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({k - 1, 0});

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        while (!pq.empty()) {
            auto [node, wt] = pq.top();
            pq.pop();
            for (const auto [ngb, w] : graph[node]) {
                if (dist[ngb] > wt + w) {
                    dist[ngb] = wt + w;
                    pq.push({ngb, dist[ngb]});
                }
            }
        }

        int maxVal = INT_MIN;
        for (const int x : dist) {
            if (x == INT_MAX) return -1;
            
            maxVal = max(maxVal, x);
        }

        return maxVal;
    }
};
