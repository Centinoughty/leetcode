// Number of Islands II
// HARD
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

class DisjointSet {
private:
    unordered_map<int, int> parent, rank;
    int components = 0;

public:
    DisjointSet() {}

    int findPar(int u) {
        if (parent.find(u) == parent.end()) {
            components ++;
            parent[u] = u;
            rank[u] = 0;
        }
        
        if (u == parent[u]) {
            return u;
        }

        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        components --;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu] ++;
        }

        return;
    }

    int countComps() {
        return components;
    }
};

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q) {
    DisjointSet ds;

    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    unordered_set<int> st;
    vector<int> res;
    for (const vector<int>& query : queries) {
        int x = query[0], y = query[1];
        int pos = x * m + y;

        if (st.count(pos)) {
            res.push_back(ds.countComps());
            continue;
        }

        st.insert(pos);
        ds.findPar(pos);

        for (const auto& dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx < 0 || ny < 0 || nx == n || ny == m) continue;

            int newPos = nx * m + ny;
            if (st.count(newPos)) {
                ds.unionByRank(newPos, pos);
            }
        }

        res.push_back(ds.countComps());
    }

    return res;
}
