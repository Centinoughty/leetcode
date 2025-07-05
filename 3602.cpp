// Hexadecimal and hexatrigecimal conversion
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string concatHex36(int n) {
        return hexDec(n) + hexTri(n);
    }

private:
    string hexDec(int n) {
        string res;
        n = n * n;
        while (n) {
            int temp = n % 16;
            if (temp < 10) {
                res = char('0' + temp) + res;
            } else {
                res = char('A' + temp - 10) + res;
            }
            n /= 16;
        }
        return res;
    }

    string hexTri(int n) {
        string res;
        n = n * n * n;
        while (n) {
            int temp = n % 36;
            if (temp < 10) {
                res = char('0' + temp) + res;
            } else {
                res = char('A' + temp - 10) + res;
            }
            n /= 36;
        }
        return res;
    }
};
