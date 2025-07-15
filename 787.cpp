// Cheapest flights within k stops
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;

        q.push({0, src});
        dist[src] = 0;

        while (!q.empty() && k >= 0) {
            int size = q.size();
            vector<int> temp = dist;

            for (int i = 0; i < size; i++) {
                auto [wg, top] = q.front();
                q.pop();
                
                for (const auto& [ngb, w] : graph[top]) {
                    if (temp[ngb] > wg + w) {
                        temp[ngb] = wg + w;
                        q.push({temp[ngb], ngb});
                    }
                }
            }

            dist = temp;
            k--;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
