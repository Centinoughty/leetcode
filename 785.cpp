// Is graph bipartite?
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        color = vector<int>(graph.size(), -1);
        for (int i = 0; i < graph.size(); i ++) {
            if (color[i] == -1) {
                if (!dfs(graph, i, 0)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<int> color;

    bool dfs(vector<vector<int>>& graph, int pos, int c) {
        color[pos] = c;
        for (const int ngb : graph[pos]) {
            if (color[ngb] == -1) {
                if (!dfs(graph, ngb, !c)) {
                    return false;
                }
            } else if (color[ngb] == c) {
                return false;
            }
        }

        return true;
    }
};

// Using BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        visited = vector<int>(graph.size(), 0);
        for (int i = 0; i < graph.size(); i ++) {
            if (!visited[i]) {
                if (!bfs(graph, i, 1)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<int> visited;

    bool bfs(vector<vector<int>>& graph, int pos, int c) {
        visited[pos] = c;
        queue<pair<int, int>> q;
        q.push({pos, c});
        while (!q.empty()) {
            const auto [node, color] = q.front();
            q.pop();
            for (const int ngb : graph[node]) {
                if (!visited[ngb]) {
                    q.push({ngb, -color});
                    visited[ngb] = -color;
                } else if (color == visited[ngb]) {
                    return false;
                }
            }
        }

        return true;
    }
};
