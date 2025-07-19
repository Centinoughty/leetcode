// Making a large island
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;

        int id = 2;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid.size(); j ++) {
                if (grid[i][j] == 1) {
                    mp[id] = dfs(grid, id, i, j);
                    id ++;
                }
            }
        }

        for (const auto x : mp) {
            cout << x.second << " ";
        }

        if (mp.size() == 0) return 1;

        if (mp.size() == 1) {
            if (mp[id - 1] == grid.size() * grid.size()) {
                return mp[id - 1];
            } else {
                return mp[id - 1] + 1;
            }
        }

        int maxVal = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid.size(); j ++) {
                if (grid[i][j] == 0) {
                    int val = 1;
                    unordered_set<int> visited;
                    if (i > 0 && !visited.count(grid[i - 1][j])) {
                        if (mp.find(grid[i - 1][j]) != mp.end()) {
                            val += mp[grid[i - 1][j]];
                            visited.insert(grid[i - 1][j]);
                        }
                    }

                    if (i < grid.size() - 1 && !visited.count(grid[i + 1][j])) {
                        if (mp.find(grid[i + 1][j]) != mp.end()) {
                            val += mp[grid[i + 1][j]];
                            visited.insert(grid[i + 1][j]);
                        }
                    }

                    if (j > 0 && !visited.count(grid[i][j - 1])) {
                        if (mp.find(grid[i][j - 1]) != mp.end()) {
                            val += mp[grid[i][j - 1]];
                            visited.insert(grid[i][j - 1]);
                        }
                    }

                    if (j < grid.size() - 1 && !visited.count(grid[i][j + 1])) {
                        if (mp.find(grid[i][j + 1]) != mp.end()) {
                            val += mp[grid[i][j + 1]];
                            visited.insert(grid[i][j + 1]);
                        }
                    }

                    maxVal = max(val, maxVal);
                }
            }
        }

        return maxVal;
    }

private:
    int dfs(vector<vector<int>>& grid, int id, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid.size()) {
            return 0;
        }

        if (grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = id;
        return 1 + dfs(grid, id, i, j - 1) + dfs(grid, id, i, j + 1) +
               dfs(grid, id, i - 1, j) + dfs(grid, id, i + 1, j);
    }
};
