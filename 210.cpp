// Course schedule II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        pathVisited = vector<bool>(numCourses, false);
        vector<vector<int>> graph(numCourses);
        for (const auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i ++) {
            if (!visited[i]) {
                if (isCycle(graph, i)) {
                    return res;
                }
            }
        }

        visited = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; i ++) {
            if (!visited[i]) {
                topoSort(graph, i);
            }
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }

private:
    vector<bool> visited, pathVisited;
    vector<int> res;
    stack<int> st;

    bool isCycle(vector<vector<int>>& graph, int pos) {
        visited[pos] = true;
        pathVisited[pos] = true;

        for (const int ngb : graph[pos]) {
            if (!visited[ngb]) {
                if (isCycle(graph, ngb)) {
                    return true;
                }
            } else if (pathVisited[ngb]) {
                return true;
            }
        }

        pathVisited[pos] = false;
        return false;
    }

    void topoSort(vector<vector<int>>& graph, int pos) {
        visited[pos] = true;

        for (const int ngb : graph[pos]) {
            if (!visited[ngb]) {
                topoSort(graph, ngb);
            }
        }

        st.push(pos);
    }
};
