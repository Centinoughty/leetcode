// Exactly One Consecutive Set Bit Pairs
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0, cons = 0;
        while (n >= 1) {
            if (n % 2 == 1) {
                cons ++;
                if (cons >= 2) {
                    cnt ++;
                }
            } else {
                cons = 0;
            }

            n /= 2;
        }

        return cnt == 1;
    }
};
