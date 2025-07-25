// Number of subarrays of size k and average greater than or equal to threshold
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int currVal = 0;
        for (int i = 0; i < k; i ++) {
            currVal += arr[i];
        }

        int avgVal = currVal / k;
        if (avgVal >= threshold) {
            count ++;
        }

        for (int i = k; i < arr.size(); i ++) {
            currVal += arr[i];
            currVal -= arr[i - k];
            avgVal = currVal / k;
            if (avgVal >= threshold) {
                count ++;
            }
        }

        return count;
    }
};
