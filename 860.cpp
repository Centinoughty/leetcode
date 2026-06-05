// Lemonade Change
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0, c = 0;
        for (const int& bill : bills) {
            if (bill == 5) {
                a ++;
            } else if (bill == 10) {
                if (a) {
                    a --;
                } else {
                    return false;
                }

                b ++;
            } else {
                if (b && a) {
                    b --;
                    a --;
                } else if (!b && a > 2) {
                    a -= 3;
                } else {
                    return false;
                }

                c ++;
            }
        }

        return true;
    }
};
