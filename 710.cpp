// Random pick with blacklist
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> mp;
    int validNo;

public:
    Solution(int n, vector<int>& blacklist) {
        validNo = n - blacklist.size();
        
        unordered_set<int> black(blacklist.begin(), blacklist.end());

        int last = n - 1;
        for (int b : black) {
            if (b < validNo) {
                while (black.count(last)) {
                    last --;
                }

                mp[b] = last;
                last --;
            }
        }
    }
    
    int pick() {
        int r = rand() % validNo;
        return mp.count(r) ? mp[r] : r;
    }
};
