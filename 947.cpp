// Most stones removed with same row or column
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (const auto stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int size = maxRow + maxCol + 1;
        unordered_map<int, int> parent;
        for (const auto stone : stones) {
            int u = stone[0], v = stone[1] + maxRow + 1;
            parent[u] = u;
            parent[v] = v;
        }

        for (const auto stone : stones) {
            int u = stone[0], v = stone[1] + maxRow + 1;
            int pu = findPar(parent, u), pv = findPar(parent, v);

            if (pu == pv) {
                continue;
            }

            parent[pu] = pv;
        }

        unordered_set<int> st;
        for (const auto stone : stones) {
            int u = stone[0];
            st.insert(findPar(parent, u));
        }

        return stones.size() - st.size();
    }

private:
    int findPar(unordered_map<int, int>& parent, int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findPar(parent, parent[node]);
    }
};

// Disjoint Set
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i ++) {
            parent[i] = i;
        }
    }

    int findPar(int u) {
        if (u == parent[u]) {
            return u;
        }

        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu] ++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int maxRow = 0;
        int maxCol = 0;
        for (const vector<int>& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_set<int> st;
        for (const vector<int>& stone : stones) {
            int row = stone[0];
            int col = stone[1] + maxRow + 1;

            ds.unionByRank(row, col);
            st.insert(row);
            st.insert(col);
        }

        int count = 0;
        for (const int& x : st) {
            if (ds.findPar(x) == x) {
                count ++;
            }
        }

        return n - count;
    }
};
