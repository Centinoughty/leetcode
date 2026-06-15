// Critical Connections in a Network
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        in.resize(n);
        low.resize(n);
        visited.resize(n, false);

        vector<vector<int>> adj(n);
        for (const vector<int>& connection : connections) {
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;
        dfs(adj, bridges, 0, -1);

        return bridges;
    }

private:
    vector<int> in, low;
    vector<bool> visited;
    int timer = 1;

    void dfs(vector<vector<int>>& adj, vector<vector<int>>& bridges, int node, int parent) {
        in[node] = low[node] = timer;
        visited[node] = true;

        timer ++;
        for (const int& ngb : adj[node]) {
            if (ngb == parent) continue;

            if (visited[ngb]) {
                low[node] = min(low[node], low[ngb]);
            } else {
                dfs(adj, bridges, ngb, node);
                low[node] = min(low[node], low[ngb]);
                
                if (low[ngb] > in[node]) {
                    bridges.push_back({ngb, node});
                }
            }
        }
    }
};
