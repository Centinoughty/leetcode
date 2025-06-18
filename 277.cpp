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

// Using a stack
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        int n = mat.size();
        for (int i = 0; i < mat.size(); i ++) {
            st.push(i);
        }
        
        while (st.size() > 1) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if (mat[a][b]) {
                st.push(b);
            } else {
                st.push(a);
            }
        }
        
        int top = st.top();
        st.pop();
        for (int i = 0; i < mat.size(); i ++) {
            if (i == top) continue;
            
            if (mat[top][i] || !mat[i][top]) {
                return -1;
            }
        }
        
        return top;
    }
};

// 2 pointer approach
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int i = 0, j = mat.size() - 1;
        while (i < j) {
            if (mat[i][j]) {
                i ++;
            } else {
                j --;
            }
        }
        
        for (int k = 0; k < mat.size(); k ++) {
            if (k == i) continue;

            if (!mat[k][i] || mat[i][k]) {
                return -1;
            }
        }
        
        return i;
    }
};
