// Check Divisibility by Digit Sum and Product
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prd = 1;
        int temp = n;
        while (temp) {
            sum += (temp % 10);
            prd *= (temp % 10);

            temp /= 10;
        }

        return n % (sum + prd) == 0;
    }
};
