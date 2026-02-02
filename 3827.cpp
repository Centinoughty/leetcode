// Count monobit integers
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
        int count = 1;
        if (n == 1) count ++;
        if (n > 1) count += log2(n + 1);

        return count;
    }
};
