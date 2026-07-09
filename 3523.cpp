// Path Existence Queries in Graph I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv] ++;
        }
    }

private:
    vector<int> parent, rank;
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);

        for (int i = 1; i < n; i ++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                ds.unionByRank(i, i - 1);
            }
        }

        vector<bool> res;
        for (const vector<int>& query : queries) {
            int u = query[0], v = query[1];
            int pu = ds.findParent(u);
            int pv = ds.findParent(v);

            res.push_back(pu == pv);
        }

        return res;
    }
};
