// Divisible Game
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        unordered_set<int> st;
        st.insert(2);
        for (const int& num : nums) {
            if (num > 1) st.insert(num);

            for (int d = 2; d <= ceil(sqrt(num)); d ++) {
                if ((num % d) == 0) {
                    st.insert(d);
                    if (num / d != 1) st.insert(num / d);
                }
            }
        }

        int maxScore = INT_MIN, maxK = 2;
        for (const int& k : st) {
            int score = getScore(nums, k);
            if (score > maxScore || (score == maxScore && k < maxK)) {
                maxScore = score;
                maxK = k;
            }
        }

        return (1LL * maxScore * maxK + MOD) % MOD;
    }

private:
    int getScore(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0, score = INT_MIN;
        for (int i = 0; i < n; i ++) {
            int curr;
            if ((nums[i] % k) == 0) {
                curr = nums[i];
            } else {
                curr = -nums[i];
            }

            prefix += curr;
            score = max(score, prefix);
            if (prefix < 0) {
                prefix = max(0, curr);
            }
        }

        return score;
    }
};
