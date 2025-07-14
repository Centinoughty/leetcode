// Number of distinct islands
// MEDIUM
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> tmp;
                    baseI = i;
                    baseJ = j;
                    dfs(grid, i, j, tmp);
                    st.insert(tmp);
                }
            }
        }
        
        
        return st.size();
    }

private:
    vector<vector<bool>> visited;
    int baseI, baseJ;
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& tmp) {
        visited[i][j] = true;
        
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        for (const auto dir : dirs) {
            int dx = dir.first, dy = dir.second;
            int nx = i + dx, ny = j + dy;
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                if (!visited[nx][ny] && grid[nx][ny]) {
                    tmp.push_back({nx - baseI, ny - baseJ});
                    dfs(grid, nx, ny, tmp);
                }
            }
        }
    }
};
