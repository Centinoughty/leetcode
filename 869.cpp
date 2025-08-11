// Reordered power of 2
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string newN = sortS(n);
        for (int i = 0; i < 32; i ++) {
            if (sortS(1 << i) == newN) {
                return true;
            }
        }

        return false;
    }

private:
    string sortS(int n) {
        string temp = to_string(n);
        sort(temp.begin(), temp.end());
        return temp;
    }
};
