// Combinations
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        genComb(1, n, k);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> temp;

    void genComb(int pos, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = pos; i <= n; i ++) {
            temp.push_back(i);
            genComb(i + 1, n, k);
            temp.pop_back();
        }
    }
};
