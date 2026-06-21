// Valid Subarrays with Matching Sum Digits I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count = 0;
        for (int i = 0; i < nums.size(); i ++) {
            long long sum = 0;
            for (int j = i; j < nums.size(); j ++) {
                sum += nums[j];

                if (isValid(sum, x)) {
                    count ++;
                }
            }
        }

        return count;
    }

private:
    bool isValid(long long num, int x) {
        int last = num % 10;
        int first = firstDigit(num);

        return last == x && first == x;
    }

    int firstDigit(long long num) {
        int count = log10(num);
        return num / pow(10, count);
    }
};
