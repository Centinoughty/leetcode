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
