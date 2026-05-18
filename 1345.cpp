// Jump game IV
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i ++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<bool> visited(n, false);
        visited[0] = true;

        while(!q.empty()) {
            auto [idx, lvl] = q.front(); q.pop();

            if (idx == n - 1) return lvl;

            int l = idx - 1;
            if (l >= 0 && !visited[l]) {
                visited[l] = true;
                q.push({l, lvl + 1});
            }

            int r = idx + 1;
            if (r < n && !visited[r]) {
                visited[r] = true;
                q.push({r, lvl + 1});
            }

            for (int nextIdx : mp[arr[idx]]) {
                if (!visited[nextIdx]) {
                    visited[nextIdx] = true;
                    q.push({nextIdx, lvl + 1});
                }
            }

            mp[arr[idx]].clear();
        }

        return -1;
    }
};
