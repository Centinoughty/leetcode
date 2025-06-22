// Compare version number
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int v1, v2;
        while (i < version1.length() || j < version2.length()) {
            v1 = 0;
            v2 = 0;
            while (i < version1.length() && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                i ++;
            }

            if (version1[i] == '.') {
                i ++;
            }

            while (j < version2.length() && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                j ++;
            }

            if (version2[j] == '.') {
                j ++;
            }

            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }
        }

        return 0;
    }
};
