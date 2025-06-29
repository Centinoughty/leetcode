// Kth largest element in a stream
// EASY

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());

        while (pq.size() > size) {
            pq.pop();
        }
    }
    
    int add(int val) {
        if (pq.size() < size) {
            pq.push(val);
        } else if (val >= pq.top()) {
            pq.push(val);
            pq.pop();
        }

        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;
};
