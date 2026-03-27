/*

Problem Name   : 33. Search in Rotated Sorted Array
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/search-in-rotated-sorted-array/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-27
Time           : O(log N)
Space          : O(1)

*/

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
    int binarySearch(int start, int end, vector<int>& nums, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        int ind = binarySearch(0, pivot - 1, nums, target);
        if (ind != -1)
            return ind;

        ind = binarySearch(pivot, n - 1, nums, target);

        return ind;
    }
};
