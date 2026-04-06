/*

Problem Name   : Missing Number
Platform       : LeetCode
Topic          : Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
Problem Link   : https://leetcode.com/problems/missing-number/submissions/1970745291/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-06
Approach       : Math
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        return totalSum - sum;
    }
};

/ TC = O(N)
// SC = O(1)
