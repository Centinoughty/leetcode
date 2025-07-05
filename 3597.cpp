// Partition string
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        vector<string> res;
        int i = 0;
        string temp;
        while (i < s.length()) {
            temp += s[i];
            if (!st.count(temp)) {
                st.insert(temp);
                res.push_back(temp);
                temp = "";
            }

            i ++;
        }

        if (temp != "") st.insert(temp);
        return res;
    }
};
