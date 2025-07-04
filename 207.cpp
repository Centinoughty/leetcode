// Course schedule
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        pathVisited = vector<bool>(numCourses, false);
        vector<vector<int>> graph(numCourses);

        for (const auto pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i ++) {
            if (!visited[i]) {
                if (dfs(graph, i)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<bool> visited, pathVisited;

    bool dfs(vector<vector<int>>& graph, int pos) {
        visited[pos] = true;
        pathVisited[pos] = true;

        for (const int ngb : graph[pos]) {
            if (!visited[ngb]) {
                if (dfs(graph, ngb)) {
                    return true;
                }
            } else if (pathVisited[ngb]) {
                return true;
            }
        }

        pathVisited[pos] = false;
        return false;
    }
};
