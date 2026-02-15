// Weighted word mapping
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for (const string& s : words) {
            int sum = 0;
            for (const char c : s) {
                sum += weights[c - 'a'];
            }

            sum %= 26;
            res += ('a' + 25 - sum);
        }

        return res;
    }
};
