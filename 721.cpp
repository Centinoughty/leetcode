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
