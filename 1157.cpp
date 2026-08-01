// Online Majority Element in Subarray
// HARD

#include <bits/stdc++.h>
using namespace std;

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n, {0, 0});

        for (int i = 0; i < n; i ++) {
            mp[arr[i]].push_back(i);
        }

        build(arr, 0, 0, n - 1);
    }
    
    int query(int left, int right, int threshold) {
        int key = queryFind(left, right, 0, 0, n - 1).first;

        if (key == -1) return -1;

        auto tempMp = mp[key];

        int cnt = upper_bound(tempMp.begin(), tempMp.end(), right) - lower_bound(tempMp.begin(), tempMp.end(), left);

        return cnt >= threshold ? key : -1;
    }

private:
    int n;
    vector<pair<int, int>> seg;
    unordered_map<int, vector<int>> mp;

    pair<int, int> build(vector<int>& nums, int pos, int l, int r) {
        if (l == r) return seg[pos] = {nums[l], 1};

        int mid = (l + r) / 2;

        pair<int, int> left = build(nums, 2 * pos + 1, l, mid);
        pair<int, int> right = build(nums, 2 * pos + 2, mid + 1, r);

        if (left.first == right.first) {
            return seg[pos] = {left.first, left.second + right.second};
        }

        if (left.second > right.second) {
            return seg[pos] = {left.first, left.second - right.second};
        }

        if (left.second < right.second) {
            return seg[pos] = {right.first, right.second - left.second};
        }

        return seg[pos] = {-1, 0};
    }

    pair<int, int> queryFind(int l, int r, int pos, int i, int j) {
        if (j < l || i > r) return {-1, 0};

        if (l <= i && j <= r) return seg[pos];

        int mid = (i + j) / 2;

        pair<int, int> left = queryFind(l, r, 2 * pos + 1, i, mid);
        pair<int, int> right = queryFind(l, r, 2 * pos + 2, mid + 1, j);

        if (left.second == 0) return right;
        if (right.second == 0) return left;

        if (left.first == right.first) {
            return {left.first, left.second + right.second};
        }

        if (left.second > right.second) {
            return {left.first, left.second - right.second};
        }

        if (left.second < right.second) {
            return {right.first, right.second - left.second};
        }

        return {-1, 0};
    }
};
