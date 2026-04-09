/*

Problem Name   : Maximum Subarray
Platform       : LeetCode
Topic          : Array, Divide and Conquer, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-subarray/submissions/1973604744/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : DP Memoization
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int helper(vector<int>& nums, int i, bool flag, vector<vector<int>>& dp) {
        if (i == nums.size())
            return flag ? 0 : -1e6;
        if (dp[i][flag] != -1)
            return dp[i][flag];
        if (flag)
            return dp[i][flag] =
                       max(0, nums[i] + helper(nums, i + 1, true, dp));
        return dp[i][flag] = max(helper(nums, i + 1, false, dp),
                                 nums[i] + helper(nums, i + 1, true, dp));
    }
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, -1));
        return helper(nums, 0, false, dp);
    }
};
