// Network Recovery Pathways
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(), maxWeight = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            maxWeight = max(maxWeight, w);
        }

        int l = 0, r = maxWeight;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            cout << l << " " << r << " " << mid;
            if (check(adj, online, mid, k)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }

private:
    const long long INF = LLONG_MAX;

    bool check(vector<vector<pair<int, int>>>& adj, vector<bool>& online, int minWeight, long long k) {
        int n = adj.size();
        vector<long long> dp(n, INF);
        dp[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [weight, node] = pq.top(); pq.pop();
            if (weight > dp[node]) continue;

            for (const auto& [ngb, w] : adj[node]) {
                if (!online[ngb]) continue;
                if (w < minWeight) continue;

                if (dp[ngb] > dp[node] + w) {
                    dp[ngb] = dp[node] + w;
                    pq.push({dp[ngb], ngb});
                }
            }
        }

        return dp[n - 1] <= k;
    }
};
