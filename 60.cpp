// Permutation Sequence
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 0; i < n; i ++) {
            nums.push_back(i + 1);
        }

        for (int i = 1; i < k; i ++) {
            nextPermutation(nums);
        }

        string s;
        for (int i = 0; i < nums.size(); i ++) {
            s += nums[i] + '0';
        }

        return s;
    }

private:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i --;
        }

        if (i == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int max = nums.size() - 1;
        while (max > i && nums[max] < nums[i]) {
            max --;
        }

        swap(nums[i], nums[max]);
        sort(nums.begin() + i + 1, nums.end());
    }
};
