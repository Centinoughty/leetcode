// Minimum Lights to Illuminate a Road
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        
        for (int i = 0; i < n; i ++) {
            if (lights[i] > 0) { 
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);
    
                diff[l] ++;
                if (r + 1 < n) diff[r + 1] --;
            }
        }

        int temp = 0;
        for (int i = 0; i < n; i ++) {
            temp += diff[i];
            if (temp > 0) lights[i] = -1;
        }

        int count = 0;
        int i = 0;
        while (i < n) {
            if (lights[i] == -1) {
                i ++;
            } else {
                count ++;
                int pos = min(i + 1, n - 1);
                for (int j = max(0, pos - 1); j <= min(n - 1, pos + 1); j ++) {
                    lights[j] = -1;
                }

                i = pos + 2;
            }
        }

        return count;
    }
};
