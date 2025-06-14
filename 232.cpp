// Implement queue using stacks
// EASY

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;
        while (!S.empty()) {
            int dummy = S.top();
            temp.push(dummy);
            S.pop();
        }

        S.push(x);
        while (!temp.empty()) {
            int dummy = temp.top();
            S.push(dummy);
            temp.pop();
        }
    }
    
    int pop() {
        int dummy = S.top();
        S.pop();
        return dummy;
    }
    
    int peek() {
        return S.top();
    }
    
    bool empty() {
        return S.size() == 0;
    }

private:
    stack<int> S;
};
