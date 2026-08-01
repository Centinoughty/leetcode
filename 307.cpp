// Range Sum Query - Mutable
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n, INT_MIN);

        build(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateNode(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return sumQuery(left, right, 0, 0, n - 1);
    }

private:
    int n;
    vector<int> seg;

    void build(vector<int>& nums, int pos, int l, int r) {
        if (l == r) {
            seg[pos] = nums[l];
            return;
        }
        
        int mid = (l + r) / 2;

        int left = 2 * pos + 1;
        int right = 2 * pos + 2;

        build(nums, left, l, mid);
        build(nums, right, mid + 1, r);

        seg[pos] = seg[left] + seg[right];
    }

    void updateNode(int key, int val, int pos, int l, int r) {
        if (l == r) {
            seg[pos] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (key <= mid) {
            updateNode(key, val, 2 * pos + 1, l, mid);
        } else {
            updateNode(key, val, 2 * pos + 2, mid + 1, r);
        }

        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    int sumQuery(int start, int end, int pos, int l, int r) {
        if (start > r || end < l) return 0;

        if (start <= l && r <= end) return seg[pos];

        int mid = (l + r) / 2;
        int left = sumQuery(start, end, 2 * pos + 1, l, mid);
        int right = sumQuery(start, end, 2 * pos + 2, mid + 1, r);

        return left + right;
    }
};
