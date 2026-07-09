// Minimum Cost to Connect Sticks
// MEDIUM
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

long long int minimumCostToConnectSticks(vector<int> &arr) {
     int n = arr.size();
     vector<long long> nums(n);
     for (int i = 0; i < n; i ++) {
          nums[i] = arr[i];
     }

     priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
     
     long long res = 0;
     while (pq.size() > 1) {
          long long top1 = pq.top(); pq.pop();
          long long top2 = pq.top(); pq.pop();

          res += top1 + top2;
          pq.push(top1 + top2);
     }

     return res;
}
