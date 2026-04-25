// Valid digit number
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        bool occ = false, start = false;
        while (n) {
            if (n < 10 && n % 10 == x) {
                start = true;
            } else if (n % 10 == x) {
                occ = true;
            }

            n /= 10;
        }

        return occ && !start;
    }
};
