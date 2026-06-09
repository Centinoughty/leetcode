// Flood fill
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        key = image[sr][sc];
        dfs(image, visited, sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, vector<vector<bool>> visited, int i, int j, int color) {
        if (i < 0 || j < 0 || i == image.size() || j == image[0].size()) return;

        if (visited[i][j]) return;

        if (image[i][j] == key) {
            image[i][j] = color;
            visited[i][j] = true;
            dfs(image, visited, i, j + 1, color);
            dfs(image, visited, i, j - 1, color);
            dfs(image, visited, i + 1, j, color);
            dfs(image, visited, i - 1, j, color);
        }
    }

private:
    int key;
};

// BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        
        int currColor = image[sr][sc];
        if (currColor == color) {
            return image;
        }
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (x > 0 && image[x - 1][y] == currColor) {
                image[x - 1][y] = color;
                q.push({x - 1, y});
            }

            if (y > 0 && image[x][y - 1] == currColor) {
                image[x][y - 1] = color;
                q.push({x, y - 1});
            }

            if (x < m - 1 && image[x + 1][y] == currColor) {
                image[x + 1][y] = color;
                q.push({x + 1, y});
            }

            if (y < n - 1 && image[x][y + 1] == currColor) {
                image[x][y + 1] = color;
                q.push({x, y + 1});
            }
        }

        return image;
    }
};
