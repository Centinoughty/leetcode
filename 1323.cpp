// Maximum 69 number
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }

            i ++;
        }

        return stoi(s);
    }
};
