// Replace non-coprime numbers in array
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num : nums) {
            st.push_back(num);
            while (st.size() > 1) {
                int a = st[st.size() - 2];
                int b = st[st.size() - 1];
                int hcf = gcd(a, b);
                if (hcf == 1) {
                    break;
                } else {
                    int temp = ((long long)a * b) / hcf;
                    st.pop_back();
                    st.pop_back();
                    st.push_back(temp);
                }
            }
        }

        return st;
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
};

// Initially, I used two pointer approach to insert element, if and only if gcd is 1
// However, this method wont work at all times
// Check out my method from the submission history