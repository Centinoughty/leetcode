// Vowel spellchecker
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> perf;
        unordered_map<string, string> capt, vows;

        for (const string word : wordlist) {
            perf.insert(word);
            string lower = toLower(word);
            if (capt.find(lower) == capt.end()) capt[lower] = word;
            string devow = devowel(lower);
            if (vows.find(devow) == vows.end()) vows[devow] = word;
        }

        vector<string> res;
        for (const string query : queries) {
            if (perf.count(query)) {
                res.push_back(query);
            } else {
                string lower = toLower(query);
                if (capt.find(lower) != capt.end()) {
                    res.push_back(capt[lower]);
                } else {
                    string devow = devowel(lower);
                    if (vows.find(devow) != vows.end()) {
                        res.push_back(vows[devow]);
                    } else {
                        res.push_back("");
                    }
                }
            }
        }

        return res;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string devowel(string s) {
        string t = s;
        for (char& c : t) {
            c = (isVowel(c) ? '*' : c);
        }

        return t;
    }

    string toLower(string s) {
        string t = s;
        for (char& c : t) {
            c = (c >= 'a' ? c : c - 'A' + 'a');
        }

        return t;
    }
};
