// Elevator Requests I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr = 0, res = 0;
        for (const int& req : requests) {
            res += abs(curr - req);
            curr = req;
        }

        return res;
    }
};
