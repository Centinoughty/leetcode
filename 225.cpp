// Implement stack using queues
// EASY

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    MyStack() {}
    
    void push(int x) {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; i ++) {
            int temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
    }
    
    int pop() {
        int temp = Q.front();
        Q.pop();
        return temp;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.size() == 0;
    }

private:
    queue<int> Q;
};
