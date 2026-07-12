// Number of Elapsed Seconds Between Two Times
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hourA = stoi(startTime.substr(0, 2));
        int hourB = stoi(endTime.substr(0, 2));

        int minA = stoi(startTime.substr(3, 5));
        int minB = stoi(endTime.substr(3, 5));

        int secA = stoi(startTime.substr(6));
        int secB = stoi(endTime.substr(6));

        return (hourB - hourA) * 3600 + (minB - minA) * 60 + (secB - secA);
    }
};
