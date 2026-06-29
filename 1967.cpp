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

// KMP Algorithm
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (string& pattern : patterns) {
            if (match(word, pattern)) count ++;
        }

        return count;
    }

private:
    bool match(string& s, string& p) {
        vector<int> pi = generatePi(p);
        int i = 0, j = 0;
        while (i < s.length()) {
            while (j >= 0 && s[i] != p[j]) j = pi[j];

            i ++;
            j ++;
            if (j == p.length()) return true;
        }

        return false;
    }

    vector<int> generatePi(string& p) {
        int n = p.length();
        vector<int> pi(n + 1, 0);
        pi[0] = -1;

        int i = 0, j = -1;
        while (i < n) {
            while (j >= 0 && p[i] != p[j]) j = pi[j];

            i ++;
            j ++;
            pi[i] = j;
        }

        return pi;
    }
};
