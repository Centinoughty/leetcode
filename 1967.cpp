// Number of Strings That Appear as Substrings in Word
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> st;
        for (int i = 0; i < word.length(); i ++) {
            string temp;
            for (int j = i; j < word.length(); j ++) {
                temp.push_back(word[j]);
                st.insert(temp);
            }
        }

        int count = 0;
        for (const string& pattern : patterns) {
            if (st.count(pattern)) count ++;
        }

        return count;
    }
};
