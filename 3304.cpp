// Find the kth charecter in string game I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        for (int i = 0; i <= log2(k); i ++) {
            string temp = res;
            for (char& c : temp) {
                c = c == 'z' ? 'a' : c + 1;
            }

            res += temp;
        }

        return res[k - 1];
    }
};
