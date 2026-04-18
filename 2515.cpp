// Shortest distance to target string in a circular array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i ++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                int circDist = n - dist;
                res = min(res, min(dist, circDist));
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
