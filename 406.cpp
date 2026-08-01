// Queue Reconstruction by Height
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        int n = people.size();
        vector<vector<int>> res(n, vector<int>(2, INT_MAX));

        for (int i = 0; i < n; i ++) {
            int pos = 0, h = people[i][0], cnt = people[i][1];
            while (pos < n && cnt) {
                if (res[pos][0] >= h) {
                    cnt --;
                }

                pos ++;
            }

            insert(res, pos, people[i]);
        }

        return res;
    }

private:
    void insert(vector<vector<int>>& nums, int pos, vector<int> person) {
        int n = nums.size();

        for (int i = n - 1; i > pos; i --) {
            nums[i] = nums[i - 1];
        }

        nums[pos] = person;
    }
};
