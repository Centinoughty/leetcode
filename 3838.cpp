// Weighted word mapping
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for (const string& word : words) {
            int weight = 0;
            for (const char& c : word) {
                weight += weights[c - 'a'];
            }

            res.push_back('z' - (weight % 26));
        }

        return res;
    }
};
