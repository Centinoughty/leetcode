// Valid Binary Strings with Cost Limit
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        N = n; K = k;
        string s;
        generateHelper(s, 0, 0, false);
        return res;
    }

private:
    int N, K;
    vector<string> res;
    
    void generateHelper(string& s, int pos, int cost, bool prev) {
        if (cost > K) return;
        
        if (pos == N) {
            res.push_back(s);
            return;
        }

        s.push_back('0');
        generateHelper(s, pos + 1, cost, false);
        s.pop_back();

        if (!prev) {
            s.push_back('1');
            generateHelper(s, pos + 1, cost + pos, true);
            s.pop_back();
        }
    }
};
