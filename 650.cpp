// 2 Keys Keyboard
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int temp = n;
        for (int i = 2; i <= temp; i ++) {
            while (n > 0 && n % i == 0) {
                res += i;
                n /= i;
            }
        }

        return res;
    }
};
