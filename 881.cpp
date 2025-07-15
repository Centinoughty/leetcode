// Boats to save people
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(), people.end());

        int l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                count ++;
                l ++;
                r --;
            } else {
                r --;
                count ++;
            }
        }

        return count;
    }
};
