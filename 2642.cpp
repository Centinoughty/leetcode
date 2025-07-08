// Design graph with shortest path calculator
// HARD

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<pair<int, int>>> graph;

public:
    Graph(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        this->n = n;
        this->graph = graph;
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({node1, 0});

        while (!pq.empty()) {
            auto [node, wt] = pq.top();
            pq.pop();

            for (const auto [ngb, w] : graph[node]) {
                if (dist[ngb] > w + wt) {
                    dist[ngb] = w + wt;
                    pq.push({ngb, dist[ngb]});
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};
