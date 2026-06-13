// Number of operations to make network connected
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1) return -1;

        vector<int> parent(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }

        int components = n;
        for (const auto connection : connections) {
            int pu = findPar(parent, connection[0]);
            int pv = findPar(parent, connection[1]);
            if (pu == pv) continue;

            parent[pu] = pv;
            components --;
        }

        return components - 1;
    }

private:
    int findPar(vector<int>& parent, int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findPar(parent, parent[node]);
    }
};

// Using MST
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (const vector<int>& connection : connections) {
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, false);
        priority_queue<int, vector<int>, greater<int>> pq;

        int extras = 0, components = 0;

        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                components ++;
                int pathCost = 0, edges = 0;

                pq.push(i);
                while (!pq.empty()) {
                    int node = pq.top(); pq.pop();
                    if (visited[node]) continue;
                    visited[node] = true;

                    pathCost ++;

                    for (const int& ngb : adj[node]) {
                        edges ++;
                        if (!visited[ngb]) {
                            pq.push(ngb);
                        }
                    }
                }

                edges /= 2;
                extras += edges - (pathCost - 1);
            }
        }

        return components - 1 <= extras ? components - 1 : -1;
    }
};

// BFS
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<vector<int>> adj(n);
        for (const vector<int> connection : connections) {
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0;
        vector<int> visited(n, false);

        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                components ++;
                queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int top = q.front(); q.pop();

                    for (const int ngb : adj[top]) {
                        if (!visited[ngb]) {
                            visited[ngb] = true;
                            q.push(ngb);
                        }
                    }
                }
            }
        }

        return components - 1;
    }
};
