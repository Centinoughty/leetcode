// Check Good Integer
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0, sqSum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x;
            sqSum += x * x;

            n /= 10;
        }

        return sqSum - sum >= 50;
    }
};
