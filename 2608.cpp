// Shortest cycle in a graph
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int minVal = INT_MAX;

        for (int i = 0; i < n; i ++) {
            vector<int> dist(n, -1), parent(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int top = q.front();
                q.pop();

                for (const int ngb : graph[top]) {
                    if (dist[ngb] == -1) {
                        dist[ngb] = dist[top] + 1;
                        parent[ngb] = top;
                        q.push(ngb);
                    } else if (parent[top] != ngb) {
                        int len = dist[top] + dist[ngb] + 1;
                        minVal = min(minVal, len);
                    }
                }
            }
        }

        return minVal == INT_MAX ? -1 : minVal;
    }
};
