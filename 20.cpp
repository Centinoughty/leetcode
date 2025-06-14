//  Valid parentheses
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (const char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else {
                if (stack.size() > 0) {
                    if (c == ')' && stack[stack.size() - 1] == '(') {
                        stack.pop_back();
                    } else if (c == '}' && stack[stack.size() - 1] == '{') {
                        stack.pop_back();
                    } else if (c == ']' && stack[stack.size() - 1] == '[') {
                        stack.pop_back();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return stack.size() == 0;
    }
};
