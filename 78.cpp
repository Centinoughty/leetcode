// Subsets
// MEDIUM

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> array;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i ++) {
            vector<int> temp;
            for (int j = 0; j < n; j ++) {
                if ((1 << j) & i) {
                    temp.push_back(nums[j]);
                }
            }

            array.push_back(temp);
        }

        return array;
    }
};