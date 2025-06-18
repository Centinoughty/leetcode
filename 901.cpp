// Online stock span
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        int cnt = 1;
        while (!st.empty() && st.top().first <= price) {
            cnt += st.top().second;
            st.pop();
        }

        st.push({price, cnt});
        return cnt;
    }

private:
    stack<pair<int, int>> st;
};
