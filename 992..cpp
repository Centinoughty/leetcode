// Subarrays with k different integers
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l1 = findSubarray(nums, k);
        int l2 = findSubarray(nums, k - 1);
        return l1 - l2;
    }

private:
    int findSubarray(vector<int>& nums, int k) {
        int count = 0;
        int i = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < nums.size(); j ++) {
            mp[nums[j]] ++;
            while (mp.size() > k) {
                mp[nums[i]] --;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                i ++;
            }

            count += j - i + 1;
        }

        return count;
    }
};
