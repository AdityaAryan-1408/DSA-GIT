/*

Problem Name   : Maximum Subarray
Platform       : LeetCode
Topic          : Array, Divide and Conquer, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-subarray/submissions/1973604744/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : Recursion
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int helper(vector<int>& nums, int i, bool flag) {
        if (i == nums.size())
            return flag ? 0 : -1e6;
        if (flag)
            return max(0, nums[i] + helper(nums, i + 1, true));
        return max(helper(nums, i + 1, false),
                   nums[i] + helper(nums, i + 1, true));
    }
    int maxSubArray(vector<int>& nums) { return helper(nums, 0, false); }
};
