// Min stack
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(mini, val);
        st.push(make_pair(val, mini));
    }
    
    void pop() {
        st.pop();
        if (st.size() == 0) {
            mini = INT_MAX;
        } else {
            mini = st.top().second;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
    int mini;
};
