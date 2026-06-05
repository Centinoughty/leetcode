// Range Sum Query - Immutable
// EASY

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        
        arr.resize(n + 1, 0);
        arr[1] = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            arr[i + 1] = nums[i] + arr[i];
        }
    }
    
    int sumRange(int left, int right) {
        return arr[right + 1] - arr[left];
    }

private:
    vector<int> arr;
};
