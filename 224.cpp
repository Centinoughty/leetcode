// Basic calculator
// HARD

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    int res = 0;
    int temp = 0;
    int sign = 1;
    stack<int> stack{{sign}};

    for (const char c : s) {
      if (isdigit(c)) {
        temp = temp * 10 + (c - '0');
      } else if (c == '(') {
        stack.push(sign);
      } else if (c == ')') {
        stack.pop();
      } else if (c == '+' || c == '-') {
        res += temp * sign;
        sign = (c == '+' ? 1 : -1) * stack.top();
        temp = 0;
      }
    }

    return res + temp * sign;
  }
};