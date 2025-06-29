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
