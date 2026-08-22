// Cinema Seat Allocation
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int l = 0b0111100000;
        int m = 0b0001111000;
        int r = 0b0000011110;

        unordered_map<int, int> mp;
        for (vector<int> res : reservedSeats) {
            if (res[1] == 1 || res[1] == 10) continue;

            mp[res[0]] |= (1 << (res[1] - 1));
        }

        int cnt = 0;
        for (auto [x, y] : mp) {
            if ((y & l) == 0) cnt ++;
            if ((y & r) == 0) cnt ++;

            if ((y & l) != 0 && (y & r) != 0 && (y & m) == 0) cnt ++;
        }

        cnt += 2 * (n - mp.size());
        return cnt;
    }
};
