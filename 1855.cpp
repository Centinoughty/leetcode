// Maximum distance between a pair of values
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, prevI = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        int res = INT_MIN;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                res = max(res, j - i);
                j ++;
            } else {
                i ++;
            }
        }

        return res < 0 ? 0 : res;
    }
};
