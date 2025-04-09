// Group anagrams
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> ans;
		for (string& s : strs) {
			string key = s;
			sort(key.begin(), key.end());
			ans[key].push_back(s);
		}

		vector<vector<string>> res;
		for (const pair<string, vector<string>> x : ans) {
			res.push_back(x.second);
		}

		return res;
	}
};
