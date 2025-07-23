// Maximum erasure value
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxVal = 0;
        int val = 0;
        deque<int> dq;
        unordered_set<int> st;
        for (const int num : nums) {
            if (st.count(num)) {
                while (dq.front() != num) {
                    val -= dq.front();
                    st.erase(dq.front());
                    dq.pop_front();
                }

                val -= num;
                dq.pop_front();
                st.erase(num);
            }

            dq.push_back(num);
            st.insert(num);
            val += num;
            maxVal = max(maxVal, val);
        }

        return maxVal;
    }
};
