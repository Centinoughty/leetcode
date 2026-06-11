// Number of Ways to Assign Edge Weights I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n, 0);
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        depth[0] = 0;

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (const int& child : adj[top]) {
                if (!visited[child]) {
                    visited[child] = true;
                    depth[child] = depth[top] + 1;
                    q.push(child);
                }
            }
        }

        int maxDepth = *max_element(depth.begin(), depth.end());

        return power(2, maxDepth - 1);
    }

private:
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
};
