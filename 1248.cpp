// Count number of nice subarrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l1 = numSubarray(nums, k);
        int l2 = numSubarray(nums, k - 1);
        return l1 - l2;
    }

private:
    int numSubarray(vector<int>& nums, int k) {
        int count = 0;
        int i = 0, oddCnt = 0;
        for (int j = 0; j < nums.size(); j ++) {
            if (nums[j] % 2) {
                oddCnt ++;
            }

            while (oddCnt > k) {
                if (nums[i] % 2) {
                    oddCnt --;
                }

                i ++;
            }

            count += j - i + 1;
        }

        return count;
    }
};
