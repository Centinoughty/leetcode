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
                if (!dfs(graph, i, -1, 0)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<int> color;

    bool dfs(vector<vector<int>>& graph, int pos, int parent, int c) {
        color[pos] = c;
        for (const int ngb : graph[pos]) {
            if (color[ngb] == -1) {
                if (!dfs(graph, ngb, pos, !c)) {
                    return false;
                }
            } else if (color[ngb] == c) {
                return false;
            }
        }

        return true;
    }
};
