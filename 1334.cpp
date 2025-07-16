// Find the city with the smallest number of neighbors at a threshold distance
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        for (const auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        for (int i = 0; i < n; i ++) graph[i][i] = 0;

        for (int k = 0; k < n; k ++) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    int val;
                    if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) {
                        val = INT_MAX;
                    } else {
                        val = graph[i][k] + graph[k][j];
                    }

                    graph[i][j] = min(graph[i][j], val);
                }
            }
        }

        vector<int> nodes(n, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (graph[i][j] <= distanceThreshold) {
                    nodes[i] ++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (nodes[i] <= nodes[res]) {
                res = i;
            }
        }

        return res;
    }
};
