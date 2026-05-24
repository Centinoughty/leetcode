// Minimum operations to sort a permutation
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos = -1;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }

        bool incr = true;
        for (int i = 0; i < n; i ++) {
            if (nums[(pos + i) % n] != i) {
                incr = false;
                break;
            }
        }

        int incrVal = INT_MAX;
        if (incr) {
            incrVal = min(pos, n - pos + 2);
        }

        bool decr = true;
        for (int i = 0; i < n; i ++) {
            int idx = (pos - i + n) % n;
            if (nums[idx] != i) {
                decr = false;
                break;
            }
        }

        int decrVal = INT_MAX;
        if (decr) {
            decrVal = min(n - pos, pos + 2);
        }

        int res = min(incrVal, decrVal);
        return res == INT_MAX ? -1 : res;
    }
};
