// Minimum length of string after operations
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumLength(string s) {
		int res = 0;
		int length = s.length();
		unordered_map<char, int> dict;
		
		for (char c : s) {
			dict[c] ++;
		}
		
		for (auto x : dict) {
			if (x.second % 2) {
				res ++;
			} else {
				res += 2;
			}
		}
		
		return res;
	}
};

class Solution {
public:
	int minimumLength(string s) {
		int res = 0;
		vector<int> count(26, 0);

		for (const char ch : s) {
			count[ch - 'a'] ++;
		}

		for (const int i : count) {
			if (i) {
				res += i % 2 ? 1 : 2;
			}
		}

		return res;
	}
};
