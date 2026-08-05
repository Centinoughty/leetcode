// Remove Methods from Project
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (const vector<int>& invocation : invocations) {
            int u = invocation[0], v = invocation[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(n, false);
        queue<int> q;

        vis[k] = true;
        q.push(k);

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (const int ngb : adj[top]) {
                if (!vis[ngb]) {
                    vis[ngb] = true;
                    q.push(ngb);
                }
            }
        }

        for (const vector<int>& invocation : invocations) {
            int u = invocation[0], v = invocation[1];
            adj[v].push_back(u);
        }

        vector<bool> newVis(n, false);
        
        q.push(k);
        newVis[k] = true;

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (const int ngb : adj[top]) {
                if (!newVis[ngb]) {
                    newVis[ngb] = true;
                    q.push(ngb);
                }
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i ++) {
            if (vis[i] != newVis[i]) {
                flag = true;
                break;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i ++) {
            if (!newVis[i]) {
                res.push_back(i);
            }
        }

        if (flag) {
            for (int i = 0; i < n; i ++) {
                if (newVis[i]) {
                    res.push_back(i);
                }
            }
        }

        return res;
    }
};
