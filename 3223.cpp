// Minimum length of string after operations
// MEDIUM

#include <string>
#include <unordered_map>

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
