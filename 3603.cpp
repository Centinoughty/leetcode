// Minimum cost path with alternating directions II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        using T = tuple<long long, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        long long startCost = 1LL * (0 + 1) * (0 + 1);
        dist[0][0][1] = startCost;
        pq.emplace(startCost, 0, 0, 1);

        while (!pq.empty()) {
            auto [cost, i, j, parity] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1) return cost;
            if (dist[i][j][parity] < cost) continue;

            if (parity == 1) {
                if (i + 1 < m) {
                    int ni = i + 1, nj = j;
                    long long newCost = cost + 1LL * (ni + 1) * (nj + 1);
                    if (newCost < dist[ni][nj][0]) {
                        dist[ni][nj][0] = newCost;
                        pq.emplace(newCost, ni, nj, 0);
                    }
                }
                if (j + 1 < n) {
                    int ni = i, nj = j + 1;
                    long long newCost = cost + 1LL * (ni + 1) * (nj + 1);
                    if (newCost < dist[ni][nj][0]) {
                        dist[ni][nj][0] = newCost;
                        pq.emplace(newCost, ni, nj, 0);
                    }
                }
            } else {
                long long newCost = cost + waitCost[i][j];
                if (newCost < dist[i][j][1]) {
                    dist[i][j][1] = newCost;
                    pq.emplace(newCost, i, j, 1);
                }
            }
        }

        return -1;
    }
};
