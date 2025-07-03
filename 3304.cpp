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

// By counting number of 1 bits
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + countBits(k - 1);
    }

private:
    int countBits(int k) {
        int res = 0;
        while (k) {
            if (k % 2) {
                res ++;
            }

            k /= 2;
        }

        return res;
    }
};
