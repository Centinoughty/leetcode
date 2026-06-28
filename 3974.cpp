// Maximum Total Sum of k Selected Elements
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum = 0;
        priority_queue<int> pq(nums.begin(), nums.end());

        while (k --) {
            int top = pq.top(); pq.pop();

            if (mul == 0) {
                sum += top;
            } else {
                sum += (long)top * mul;
                mul --;
            }
        }

        return sum;
    }
};
