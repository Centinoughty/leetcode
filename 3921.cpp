// Score validator
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> res(2, 0);
        for (const string& e : events) {
            if (res[1] == 10) break;

            if (e == "W") {
                res[1] ++;
            } else if (e == "WD" || e == "NB") {
                res[0] ++;
            } else {
                res[0] += (e[0] - '0');
            }
        }

        return res;
    }

private:
    bool isNum(string s) {
        return s[0] >= '0' && s[0] <= '6';
    }
};
