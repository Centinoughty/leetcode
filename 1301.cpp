// Number if Paths with Max Score
// HARD

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{m - 1, n - 1}, 0});

        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> ways(m, vector<int>(n, 0));
        dist[m - 1][n - 1] = 0;
        ways[m - 1][n - 1] = 1;

        vector<pair<int, int>> dirs = {{-1, 0}, {-1, -1}, {0, -1}};

        while (!q.empty()) {
            auto [node, weight] = q.front(); q.pop();
            auto [x, y] = node;

            if (weight != dist[x][y]) continue;

            for (const auto& [dx, dy] : dirs) {
                int nx =  x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx == m || ny == n) continue;
                if (board[nx][ny] == 'X') continue;

                int val = board[nx][ny] == 'E' ? 0 : board[nx][ny] - '0';
                int newVal = weight + val;

                if (newVal < dist[nx][ny]) continue;
                if (newVal > dist[nx][ny]) {
                    dist[nx][ny] = newVal;
                    ways[nx][ny] = ways[x][y];
                } else {
                    ways[nx][ny] = (1LL * ways[nx][ny] + ways[x][y]) % MOD;
                    continue;
                }

                q.push({{nx, ny}, newVal});
            }
        }

        return {dist[0][0], ways[0][0]};
    }
};
