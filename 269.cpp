// Alien Dictionary
// HARD
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        unordered_map<int, int> inDeg;
        
        for (const string& word : words) {
            for (const char& c : word) {
                inDeg[c - 'a'] = 0;
            }
        }


        for (int i = 0; i < n - 1; i ++) {
            int j = 0, maxi = min(words[i].size(), words[i + 1].size());
            while (j < maxi) {
                if (words[i][j] == words[i + 1][j]) {
                    j ++;
                } else {
                    int u = words[i][j] - 'a';
                    int v = words[i + 1][j] - 'a';

                    adj[u].push_back(v);
                    inDeg[v] ++;

                    break;
                }
            }
            
            if (j == maxi && words[i][j] > words[i + 1][j]) {
                return "";
            }
        }

        queue<int> q;
        for (auto& [x, y] : inDeg) {
            if (y == 0) {
                q.push(x);
            }
        }

        int cnt = 0;
        string res = "";
        while (!q.empty()) {
            int top = q.front(); q.pop();
            res.push_back(top + 'a');
            cnt ++;

            for (const int& ngb : adj[top]) {
                inDeg[ngb] --;
                if (inDeg[ngb] == 0) {
                    q.push(ngb);
                }
            }
        }

        return cnt == inDeg.size() ? res : "";
    }
};
