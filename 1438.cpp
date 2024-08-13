// Longest continuous subarray with absolute difference less than or equal to limit
// MEDIUM

#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> minQueue;
        deque<int> maxQueue;

        for (int l = 0, r = 0; r < nums.size(); r ++) {
            while (!minQueue.empty() && minQueue.back() > nums[r]) {
                minQueue.pop_back();
            }

            minQueue.push_back(nums[r]);
            while (!maxQueue.empty() && maxQueue.back() < nums[r]) {
                maxQueue.pop_back();
            }

            maxQueue.push_back(nums[r]);
            while (maxQueue.front() - minQueue.front() > limit) {
                if (minQueue.front() == nums[l]) {
                    minQueue.pop_front();
                }

                if (maxQueue.front() == nums[l]) {
                    maxQueue.pop_front();
                }

                l ++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};