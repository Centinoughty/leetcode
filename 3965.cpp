// Finish Time of Tasks I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        if (n == 1) return baseTime[0];
        
        vector<vector<int>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, baseTime, 0, -1);
    }

private:
    long long dfs(vector<vector<int>>& adj, vector<int>& time, int pos, int parent) {
        if (isLeaf(adj, pos, parent)) return time[pos];

        long long earliest = LLONG_MAX, latest = LLONG_MIN;
        for (const int& child : adj[pos]) {
            if (child == parent) continue;

            long long currTime = dfs(adj, time, child, pos);
            earliest = min(earliest, currTime);
            latest = max(latest, currTime);
        }

        long long res = latest - earliest;
        res += time[pos];
        res += latest;
        return res;
    }

    bool isLeaf(vector<vector<int>>& adj, int pos, int parent) {
        return parent != -1 && adj[pos].size() == 1;
    }
};
