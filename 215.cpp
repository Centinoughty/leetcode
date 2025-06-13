// Kth largest element in an array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = -1;
        buildHeap(nums);
        for (int i = 0; i < k; i ++) {
            res = extractMax(nums);
        }

        return res;
    }

private:
    void heapify(vector<int>& nums, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < nums.size() && nums[left] > nums[largest]) {
            largest = left;
        }

        if (right < nums.size() && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, largest);
        }
    }

    void buildHeap(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i --) {
            heapify(nums, i);
        }
    }

    int extractMax(vector<int>& nums) {
        int temp = nums[0];
        swap(nums[0], nums[nums.size() - 1]);
        nums.pop_back();
        heapify(nums, 0);
        return temp;
    }
};
