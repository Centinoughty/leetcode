// Remove sub-folders from the filesystem
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_set<string> st;
        for (const auto x : folder) {
            int i = 0;
            string temp = getSub(x, i);
            while (!st.count(temp) && i < x.length()) {
                temp = getSub(x, i);
            }

            st.insert(temp);
        }

        vector<string> res;
        for (const auto x : st) {
            res.push_back(x);
        }

        return res;
    }

private:
    string getSub (string s, int& i) {
        int pos = i + 1;
        while (pos < s.length() && s[pos] != '/') {
            pos ++;
        }

        i = pos + 1;
        return s.substr(0, pos);
    }
};
