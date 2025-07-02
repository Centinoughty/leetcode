// Number of provinces
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        visited = vector<bool>(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i ++) {
            if (!visited[i]) {
                dfsHelper(isConnected, i);
                count ++;
            }
        }

        return count;
    }

private:
    vector<bool> visited;

    void dfsHelper(vector<vector<int>> mat, int pos) {
        if (visited[pos]) return;

        visited[pos] = true;
        for (int i = 0; i < mat.size(); i ++) {
            if (i != pos && mat[pos][i]) {
                if (!visited[i]) {
                    dfsHelper(mat, i);
                }
            }
        }
    }
};
