// Total Waviness of Numbers in Range I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int num = num1; num <= num2; num ++) {
            res += getWaviness(num);
        }

        return res;
    }

private:
    int getWaviness(int n) {
        string s = to_string(n);

        int cnt = 0;
        for (int i = 1; i < s.length() - 1; i ++) {
            bool peak = s[i] > s[i - 1] && s[i] > s[i + 1];
            bool valley = s[i] < s[i - 1] && s[i] < s[i + 1];

            if (peak || valley) {
                cnt ++;
            }
        }

        return cnt;
    }
};
