/*

Problem Name   : Find Minimum in Rotated Sorted Array
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-27
Approach       : Brute Force
Time           : O(logN)
Space          : O(1)

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};
