// Subsets
// MEDIUM

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        for (int i = 0; i < (1 << nums.size()); i ++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j ++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};

// Recursive approach

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> subset;
    void dfs(vector<int> nums, int i) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1);

        subset.pop_back();
        dfs(nums, i + 1);
    }
};
