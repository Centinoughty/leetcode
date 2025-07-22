// Last stone weight
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            if (pq.empty()) {
                return abs(x - y);
            }

            if (abs(x - y)) {
                pq.push(abs(x - y));
            }
        }

        return pq.top();
    }
};
