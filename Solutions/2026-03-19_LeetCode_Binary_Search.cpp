/*

Problem Name   : Binary Search
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/binary-search/submissions/1952891250/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Time           : O(LogN)
Space          : O(1)

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
