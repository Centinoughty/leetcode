// Count valid word occurrences
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for (const string& x : chunks) {
            s += x;
        }

        unordered_map<string, int> mp;
        string word = "";
        for (int i = 0; i < s.length(); i ++) {
            if (isLetter(s[i])) {
                word += s[i];
            } else if (s[i] == '-') {
                bool l = !word.empty();
                bool r = (i + 1 < s.length() && isLetter(s[i + 1]));

                if (l && r) {
                    word += '-';
                } else {
                    if (!word.empty()) {
                        mp[word] ++;
                    }

                    word = "";
                }
            } else {
                if (!word.empty()) {
                    mp[word] ++;
                }

                word = "";
            }
        }

        if (!word.empty()) {
            mp[word] ++;
        }

        vector<int> res;
        for (const string& q : queries) {
            res.push_back(mp[q]);
        }

        return res;
    }

private:
    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
};
