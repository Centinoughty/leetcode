// Check if any element has prime frequency
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<bool> isPrime(101, true);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i <= 100; i ++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 100; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> freq(101, 0);
        for (const int num : nums) {
            freq[num] ++;
        }

        for (const int count : freq) {
            if (count > 0 && isPrime[count]) {
                return true;
            }
        }

        return false;
    }
};
