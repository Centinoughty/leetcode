// Maximum Element After Decreasing and Rearranging
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();        
        unordered_map<int, int> mp;
        for (const int& num : arr) {
            mp[num] ++;
        }

        sort(arr.begin(), arr.end());

        int k = n - 1, num = 1;
        for (int i = 0; i < n; i ++) {
            if (i == 0 && arr[i] != 1) {
                mp[arr[k]] --;
                if (mp[arr[k]] == 0) mp.erase(arr[k]);

                k --;
                continue;
            }

            if (arr[i] == num + 1) {
                num ++;
            } else if (arr[i] == num) {
                continue;
            } else {
                num ++;
                mp[arr[k]] --;
                if (mp[arr[k]] == 0) mp.erase(arr[k]);

                k --;
            }
        }

        return num;
    }
};

// Easy Approach
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int num = 1;
        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] >= num + 1) {
                num ++;
            }
        }

        return num;
    }
};
