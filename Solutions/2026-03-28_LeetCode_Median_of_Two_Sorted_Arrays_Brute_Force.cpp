/*

Problem Name   : Median of Two Sorted Arrays
Platform       : LeetCode
Topic          : Array, Binary Search, Divide and Conquer
Problem Link   : https://leetcode.com/problems/median-of-two-sorted-arrays/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-28
Approach       : Brute Force
Time           : TC = O(Log min(N, M))
Space          : SC = O(1)

*/

class Solution {
public:
    int n, m;
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& all) {
        int i = 0, j = 0;
        int ind = 0;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                all[ind] = nums1[i];
                i++;
            } else {
                all[ind] = nums2[j];
                j++;
            }
            ind++;
        }
        while (i < n) {
            all[ind] = nums1[i];
            i++;
            ind++;
        }
        while (j < m) {
            all[ind] = nums2[j];
            j++;
            ind++;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(), m = nums2.size();
        vector<int> all(n + m);
        merge(nums1, nums2, all);
        double median = 0.0;
        if ((n + m) % 2 != 0) {
            median = all[(n + m) / 2];
        } else {
            median = (all[(n + m) / 2] + all[((n + m) / 2) - 1]) / 2.0;
        }
        return median;
    }
};

// TC = O(N + M)
// SC = O(N + M)
