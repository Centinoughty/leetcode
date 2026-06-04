// Maximum Points You Can Obtain from Cards
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int l = n - k, r = n - 1;
        int sum = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int maxSum = sum;
        
        int cnt = 1;
        while (cnt <= k) {
            sum -= cardPoints[l % n];
            l ++; r ++;
            sum += cardPoints[r % n];

            cnt ++;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
