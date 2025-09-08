// Convert integer to the sum of two non-zero integers
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i ++) {
            int a = i, b = n - a;
            if ((to_string(a) + to_string(b)).find('0') == string::npos) {
                return {a, b};
            }
        }

        return {};
    }
};
