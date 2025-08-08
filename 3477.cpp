// Friuts into baskets II
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        for (const int fruit : fruits) {
            for (int& basket : baskets) {
                if (basket >= fruit) {
                    basket = 0;
                    count ++;
                    break;
                }
            }
        }

        return fruits.size() - count;
    }
};
