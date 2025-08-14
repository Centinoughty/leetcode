// Largest 3-same-digit number in string
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi = -1;
        
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < 3 && j < num.length()) {
            mp[num[j] - '0'] ++;
            j ++;
        }

        if (mp.size() == 1) {
            auto it = mp.begin();
            maxi = max(maxi, it->first);
        }

        while (j < num.length()) {
            mp[num[i] - '0'] --;
            if (mp[num[i] - '0'] == 0) {
                mp.erase(num[i] - '0');
            }

            mp[num[j] - '0'] ++;
            i ++;
            j ++;

            if (mp.size() == 1) {
                auto it = mp.begin();
                maxi = max(maxi, it->first);
            }
        }

        string res;
        if (maxi == -1) return res;

        for (int i = 0; i < 3; i ++) res += to_string(maxi);
        
        return res;
    }
};
