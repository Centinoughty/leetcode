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

// Binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n1;
        int left = (n1 + n2 + 1) / 2;
        while (l <= r) {
            int mid1 = (l + r) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 > 0) l1 = nums1[mid1 - 1];
            if (mid2 > 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2) {
                    return max(l1, l2);
                } else {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }

        return 0;
    }
};
