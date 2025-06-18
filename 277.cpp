// Find the celibrity
// MEDIUM
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        for (int j = 0; j < mat[0].size(); j ++) {
            int cnt = 0;
            for (int i = 0; i < mat.size(); i ++) {
                if (mat[i][j] == 1) {
                    cnt ++;
                }
            }
            
            if (cnt == mat.size()) {
                int tmp = 0;
                for (int i = 0; i < mat[0].size(); i ++) {
                    if (i == j || mat[j][i] == 0) {
                        tmp ++;
                    }
                }
                
                if (tmp == mat.size()) {
                    return j;
                }
            }
        }
        
        return -1;
    }
};
