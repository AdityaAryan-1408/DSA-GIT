/*

Problem Name   : Merge Sorted Array
Platform       : LeetCode
Topic          : Top Interview 150, Two Pointers
Problem Link   : https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insert = m + n - 1;
        int left = m - 1, right = n - 1;
        while (right != -1) {
            if (left >= 0 && nums1[left] > nums2[right]) {
                nums1[insert] = nums1[left];
                left--;
            } else {
                nums1[insert] = nums2[right];
                right--;
            }
            insert--;
        }
    }
};

int main() {
    Solution s;

    return 0;
}