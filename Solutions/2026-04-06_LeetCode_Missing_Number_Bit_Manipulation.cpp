/*

Problem Name   : Missing Number
Platform       : LeetCode
Topic          : Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
Problem Link   : https://leetcode.com/problems/missing-number/submissions/1970745291/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-06
Approach       : Bit Manipulation
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for (int i = 0; i < n; i++) {
            xorr ^= i ^ nums[i];
        }
        return xorr;
    }
};
