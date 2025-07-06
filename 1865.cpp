// Finding pairs with a certain sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (const int num : n2) {
            mp[num] ++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]] --;
        n2[index] += val;
        mp[n2[index]] ++;
    }
    
    int count(int tot) {
        int res = 0;
        for (const int num : n1) {
            if (mp.find(tot - num) != mp.end()) {
                res += mp[tot - num];
            }
        }

        return res;
    }

private:
    vector<int> n1, n2;
    unordered_map<int, int> mp;
};
