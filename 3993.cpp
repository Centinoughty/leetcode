// Maximum Value of an Alternating Sequence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n % 2) return maximumValue(n - 1, s, m);
        if (n == 0) return s;
        
        long long res = s;
        res = res + 1LL * (n / 2) * m;
        res = res - ((double)n / 2 - 1);
        return res;
    }
};
