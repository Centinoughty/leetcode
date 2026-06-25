// Parsing a Boolean Expression
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        return solve(expression, 0, expression.length() - 1);
    }

private:
    bool solve(string expr, int l, int r) {
        if (l > r) return false;

        int flag = -1;
        if (expr[l] == 'f') {
            return false;
        } else if (expr[l] == 't') {
            return true;
        } else if (expr[l] == '&') {
            int cnt = 1;
            l += 2;
            int newR = l;

            while (cnt && newR < expr.length()) {
                if (expr[newR] == '(') cnt ++;
                else if (expr[newR] == ')') cnt --;

                newR ++;
            }

            int prev = l;
            cnt = 0;
            for (int i = l; i <= newR; i ++) {
                if (expr[i] == ',' && cnt == 0 || i == newR) {
                    if (flag == -1) {
                        flag = solve(expr, prev, i - 1);
                    } else {
                        flag &= solve(expr, prev, i - 1);
                    }

                    prev = i + 1;
                } else if (expr[i] == '(') {
                    cnt ++;
                } else if (expr[i] == ')') {
                    cnt --;
                }
            }
        } else if (expr[l] == '|') {
            int cnt = 1;
            l += 2;
            int newR = l;

            while (cnt && newR < expr.length()) {
                if (expr[newR] == '(') cnt ++;
                else if (expr[newR] == ')') cnt --;

                newR ++;
            }

            int prev = l;
            cnt = 0;
            for (int i = l; i <= newR; i ++) {
                if (expr[i] == ',' && cnt == 0 || i == newR) {
                    if (flag == -1) {
                        flag = solve(expr, prev, i - 1);
                    } else {
                        flag |= solve(expr, prev, i - 1);
                    }

                    prev = i + 1;
                } else if (expr[i] == '(') {
                    cnt ++;
                } else if (expr[i] == ')') {
                    cnt --;
                }
            }
        } else {
            flag = !solve(expr, l + 2, r - 1);
        }

        return flag == 1;
    }
};
