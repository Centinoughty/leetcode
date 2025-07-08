// Word ladder
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for (const string& s : wordList) {
            st.insert(s);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.insert(beginWord);
        while (!q.empty()) {
            auto [word, pos] = q.front();
            q.pop();
            st.erase(word);

            if (word == endWord) {
                return pos;
            }

            for (int i = 0; i < word.length(); i ++) {
                string temp = word;
                temp[i] = 'a';
                for (int j = 0; j < 26; j ++) {
                    if (st.count(temp) && temp != word) {
                        q.push({temp, pos + 1});
                    }

                    temp[i] ++;
                }
            }
        }

        return 0;
    }
};
