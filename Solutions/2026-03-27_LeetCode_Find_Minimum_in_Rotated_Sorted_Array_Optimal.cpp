/*

Problem Name   : Find Minimum in Rotated Sorted Array
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-27
Approach       : Optimal
Time           : O(logN)
Space          : O(1)

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[high];
    }
};
