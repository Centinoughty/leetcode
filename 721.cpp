// Accounts merge
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);

        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u), pv = findPar(v);
        if (pu == pv) return;
        
        int ru = rank[pu], rv = rank[pv];
        if (ru == rv) {
            parent[pv] = pu;
            rank[pu] ++;
        } else if (ru < rv) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        unordered_map<string, int> mp;
        int curr = 0;
        for (const auto account : accounts) {
            for (int i = 1; i < account.size(); i ++) {
                string mail = account[i];
                if (mp.find(mail) != mp.end()) {
                    ds.unionByRank(curr, mp[mail]);
                } else {
                    mp[mail] = curr;
                }
            }

            curr ++;
        }

        unordered_set<int> st;
        for (const auto x : mp) {
            st.insert(ds.findPar(x.second));
        }

        unordered_map<int, vector<string>> temp;
        for (const auto x : st) {
            temp[x] = {};
        }

        for (const auto [mail, par] : mp) {
            int ult = ds.findPar(par);
            temp[ult].push_back(mail);
        }

        vector<vector<string>> res;
        for (auto& [par, mails] : temp) {
            sort(mails.begin(), mails.end());
            mails.insert(mails.begin(), accounts[par][0]);
            res.push_back(mails);
        }

        return res;
    }

private:
    int findPar(vector<int>& parent, int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findPar(parent, parent[node]);
    }
};

// Simple Disjoint Set
class DisjointSet {
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i ++) {
            parent[i] = i;
        }
    }

    int findPar(int u) {
        if (u == parent[u]) {
            return u;
        }

        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu] ++;
        }

        return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        unordered_map<int, string> names;

        DisjointSet ds(accounts.size());
        
        int pos = 0;
        for (const vector<string>& account : accounts) {
            names[pos] = account[0];
            for (int i = 1; i < account.size(); i ++) {
                if (mp.find(account[i]) == mp.end()) {
                    mp[account[i]] = pos;
                } else {
                    ds.unionByRank(mp[account[i]], pos);
                }
            }

            pos ++;
        }

        unordered_map<int, int> newPos;
        vector<vector<string>> res;
        for (int i = 0; i < pos; i ++) {
            if (i == ds.findPar(i)) {
                newPos[i] = res.size();
                res.push_back({names[i]});
            }
        }

        for (const auto& [x, y] : mp) {
            int py = ds.findPar(y);
            res[newPos[py]].push_back(x);
        }

        for (vector<string>& account : res) {
            sort(account.begin() + 1, account.end());
        }

        return res;
    }
};
