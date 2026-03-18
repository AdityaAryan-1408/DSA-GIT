/*

Problem Name   : Two Sum II - Input Array Is Sorted
Platform       : LeetCode
Topic          : Array, Two Pointers, Binary Search
Problem Link   : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1952391510/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-18
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i + 1, j + 1};
            if (sum > target)
                j--;
            else
                i++;
        }
        return {-1, -1};
    }
};
