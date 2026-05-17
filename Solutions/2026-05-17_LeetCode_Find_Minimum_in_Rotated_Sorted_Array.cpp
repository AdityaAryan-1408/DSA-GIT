/*

Problem Name   : Find Minimum in Rotated Sorted Array
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/2005326298/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-17
Time           : O(log N), but for worst Case - O(N)
Space          : O(1)

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int resultInd = 0;
        while (l <= r) {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[resultInd]) {
                resultInd = mid;
            }
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[resultInd];
    }
};
