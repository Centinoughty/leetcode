// Largest Integer With Given Digit Sum
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {
        int res = 0;
        int tmp1 = s / 9, tmp2 = s % 9;
        
        if (ceil((double)s / 9) > n) return -1;

        while (tmp1 --) {
            res = res * 10 + 9;
            n --;
        }

        while (n --) {
            res = res * 10 + tmp2;
            tmp2 = 0;
        }

        return res;
    }
};
