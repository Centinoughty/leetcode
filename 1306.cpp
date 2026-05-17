// Jump game III
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = false;

        while (!q.empty()) {
            int top = q.front(); q.pop();

            if (arr[top] == 0) return true;

            int l = top - arr[top];
            int r = top + arr[top];

            if (l >= 0 && !visited[l]) {
                visited[l] = true;
                q.push(l);
            }

            if (r < n && !visited[r]) {
                visited[r] = true;
                q.push(r);
            }
        }

        return false;
    }
};
