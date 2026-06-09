// Count the number of Complete Components
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        vector<int> visited(n, false);

        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                queue<int> q;

                q.push(i);
                visited[i] = true;

                int size = 0, edges = 0;

                while (!q.empty()) {
                    int top = q.front(); q.pop();
                    size ++;

                    for (const int& node : adj[top]) {
                        edges ++;
                        if (!visited[node]) {
                            visited[node] = true;
                            q.push(node);
                        }
                    }
                }

                if (size * (size - 1) == edges) count ++;
            }
        }

        return count;
    }
};
