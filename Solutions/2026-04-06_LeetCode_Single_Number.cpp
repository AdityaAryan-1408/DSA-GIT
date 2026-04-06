/*

Problem Name   : Single Number
Platform       : LeetCode
Topic          : Array, Bit Manipulation
Problem Link   : https://leetcode.com/problems/single-number/submissions/1544149047/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-06
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
