// Median of two sorted arrays
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i ++]);
            } else {
                merged.push_back(nums2[j ++]);
            }
        }

        while (i < nums1.size()) {
            merged.push_back(nums1[i ++]);
        }

        while (j < nums2.size()) {
            merged.push_back(nums2[j ++]);
        }

        int n = nums1.size() + nums2.size();
        if (n % 2) {
            return (double)merged[n / 2];
        } else {
            return (double)((double)merged[n / 2] + (double)merged[n / 2 - 1]) / 2.0;
        }
    }
};

// No extra space
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int el1 = -1, el2 = -1;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int pos1 = n % 2 ? n / 2 : n / 2 - 1;
        int pos2 = n / 2;
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2) {
            int temp;
            if (nums1[i] < nums2[j]) {
                temp = nums1[i ++];
            } else {
                temp = nums2[j ++];
            }

            if (k == pos1 && el1 == -1 && el2 == -1) {
                el1 = temp;
            }

            if (k == pos2 && el1 != -1 && el2 == -1) {
                el2 = temp;
                break;
            }

            k ++;
        }

        while (i < n1 && el2 == -1) {
            int temp = nums1[i ++];
            if (k == pos1 && el1 == -1 && el2 == -1) {
                el1 = temp;
            }

            if (k == pos2 && el1 != -1 && el2 == -1) {
                el2 = temp;
            }

            k ++;
        }

        while (j < n2 && el2 == -1) {
            int temp = nums2[j ++];
            if (k == pos1 && el1 == -1 && el2 == -1) {
                el1 = temp;
            }

            if (k == pos2 && el1 != -1 && el2 == -1) {
                el2 = temp;
            }

            k ++;
        }

        return ((double)el1 + (double)el2) / 2.0;
    }
};
