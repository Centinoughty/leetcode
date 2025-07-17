// Number of operations to make network connected
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1) return -1;

        vector<int> parent(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }

        int components = n;
        for (const auto connection : connections) {
            int pu = findPar(parent, connection[0]);
            int pv = findPar(parent, connection[1]);
            if (pu == pv) continue;

            parent[pu] = pv;
            components --;
        }

        return components - 1;
    }

private:
    int findPar(vector<int>& parent, int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findPar(parent, parent[node]);
    }
};
