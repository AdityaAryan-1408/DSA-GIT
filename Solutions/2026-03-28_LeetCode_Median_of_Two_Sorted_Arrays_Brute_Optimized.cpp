/*

Problem Name   : Median of Two Sorted Arrays
Platform       : LeetCode
Topic          : Array, Binary Search, Divide and Conquer
Problem Link   : https://leetcode.com/problems/median-of-two-sorted-arrays/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-28
Approach       : Brute - Optimized
Time           : TC = O(Log min(N, M))
Space          : SC = O(1)

*/

class Solution {
public:
    int n, m;

    double merge(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        int total = n + m;
        int mid = total / 2;

        int cnt = 0;
        int prev = -1, curr = -1;

        while (i < n || j < m) {
            prev = curr;

            if (i < n && (j >= m || a[i] <= b[j])) {
                curr = a[i];
                i++;
            } else {
                curr = b[j];
                j++;
            }

            if (cnt == mid) {
                if (total % 2 == 1) {
                    return curr;
                } else {
                    return (prev + curr) / 2.0;
                }
            }
            cnt++;
        }
        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        return merge(nums1, nums2);
    }
};

// TC = O(N + M)
// SC = O(1)
