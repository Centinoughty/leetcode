// Roman to integer
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        char prev = '\0';
        for (const char c : s) {
            switch (c) {
                case 'I':
                    res += 1;
                    break;
                
                case 'V':
                    res += 5;
                    break;
                
                case 'X':
                    res += 10;
                    break;
                
                case 'L':
                    res += 50;
                    break;
                
                case 'C':
                    res += 100;
                    break;
                
                case 'D':
                    res += 500;
                    break;
                
                case 'M':
                    res += 1000;
                    break;
            }

            if (c == 'V' || c == 'X') {
                if (prev == 'I') {
                    res -= 2;
                }
            }

            if (c == 'L' || c == 'C') {
                if (prev == 'X') {
                    res -= 20;
                }
            }

            if (c == 'D' || c == 'M') {
                if (prev == 'C') {
                    res -= 200;
                }
            }

            prev = c;
        }

        return res;
    }
};
