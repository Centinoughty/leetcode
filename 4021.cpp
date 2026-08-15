// Minimum Operations to Make a Rotated Palindrome I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        int minVal = INT_MAX;
        for (int i = 0; i < n; i ++) {
            int score = 0;
            for (int j = 0; j < n / 2; j ++) {
                if (s[j] != s[n - j - 1]) {
                    int l = (s[n - j - 1] - s[j] + 26) % 26;
                    int r = (s[j] - s[n - j - 1] + 26) % 26;

                    score += min(l, r);
                }
            }

            char temp = s[0];
            s.erase(0, 1);
            s.push_back(temp);

            minVal = min(minVal, score + i);
        }

        return minVal;
    }
};
