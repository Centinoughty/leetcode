// Hand of Straights
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;

        map<int, int> mp;
        for (const int& num : hand) {
            mp[num] ++;
        }

        for (int i = 0; i < n / groupSize; i ++) {
            auto it = mp.begin();
            int x = it->first;
            for (int k = 0; k < groupSize; k ++) {
                if (mp.find(x) != mp.end()) {
                    mp[x] --;
                    if (mp[x] == 0) {
                        mp.erase(x);
                    }

                    x ++;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
