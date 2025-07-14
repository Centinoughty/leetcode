// Find eventual safe states
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> newG(graph.size());
        vector<int> inDeg(graph.size(), 0);
        for (int i = 0; i < graph.size(); i ++) {
            for (const int x : graph[i]) {
                newG[x].push_back(i);
                inDeg[i] ++;
            }
        }

        queue<int> q;
        for (int i = 0; i < graph.size(); i ++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);

            for (const int ngb : newG[top]) {
                if (--inDeg[ngb] == 0) {
                    q.push(ngb);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
