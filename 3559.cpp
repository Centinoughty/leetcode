// Number of Ways to Assign Edge Weights II
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> pow2(n);
        for (int i = 0; i < n; i ++) {
            pow2[i] = power(2, i);
        }

        vector<bool> visited(n, false);
        vector<int> parent(n);
        depth.resize(n);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        parent[0] = -1;
        depth[0] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (const int& child : adj[node]) {
                if (!visited[child]) {
                    visited[child] = true;
                    depth[child] = depth[node] + 1;
                    parent[child] = node;
                    q.push(child);
                }
            }
        }

        LOG = 0;
        while ((1 << LOG) <= n) LOG ++;

        up.assign(n, vector<int>(LOG, -1));
        for (int v = 0; v < n; v ++) {
            up[v][0] = parent[v];
        }

        for (int j = 1; j < LOG; j++) {
            for (int v = 0; v < n; v++) {
                if (up[v][j - 1] != -1) {
                    up[v][j] = up[up[v][j - 1]][j - 1];
                }
            }
        }

        vector<int> res;
        for (const vector<int>& query : queries) {
            int node1 = query[0] - 1, node2 = query[1] - 1;

            int len = depth[node1] + depth[node2] - 2 * depth[lca(node1, node2)];

            res.push_back(len == 0 ? 0 : pow2[len - 1]);
        }

        return res;
    }

private:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    int power(long long base, long long exp) {
        long long res = 1;
        const int MOD = 1e9 + 7;

        while (exp) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int lca(int u, int v) {

        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }
};
