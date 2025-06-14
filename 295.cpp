// Find median from data stream
// HARD

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);

        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int n1 = maxHeap.size(), n2 = minHeap.size();
        if ((n1 + n2) % 2) {
            return n1 > n2 ? maxHeap.top() : minHeap.top();
        } else {
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
    }

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
