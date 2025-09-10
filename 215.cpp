// Kth largest element in an array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);
        int res = -1;
        for (int i = 0; i < k; i ++) {
            res = extractMax(nums);
        }

        return res;
    }

private:
    void heapify(vector<int>& nums, int i) {
        int largest = i;
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l < nums.size() && nums[l] > nums[largest]) {
            largest = l;
        }

        if (r < nums.size() && nums[r] > nums[largest]) {
            largest = r;
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
        int res = nums[0];
        swap(nums[0], nums[nums.size() - 1]);
        nums.pop_back();
        heapify(nums, 0);
        return res;
    }
};

// Approach: Quick Select
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, nums.size() - k, 0, nums.size() - 1);
    }

private:
    int quickSelect(vector<int>& nums, int k, int i, int j) {
        if (i == j) return nums[i];

        int p = partition(nums, i, j);
        if (p == k) {
            return nums[p];
        } else if (p < k) {
            return quickSelect(nums, k, p + 1, j);
        } else {
            return quickSelect(nums, k, i, p - 1);
        }
    }

    int partition(vector<int>& nums, int i, int j) {
        int pivot = nums[i];
        int l = i + 1, r = j;
        while (l <= r) {
            while (l <= j && nums[l] <= pivot) l ++;
            while (r >= i && nums[r] > pivot) r --;

            if (l < r) {
                swap(nums[l], nums[r]);
            } else {
                break;
            }
        }

        swap(nums[i], nums[r]);
        return r;
    }
};
