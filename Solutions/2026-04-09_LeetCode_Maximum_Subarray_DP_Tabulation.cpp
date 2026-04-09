/*

Problem Name   : Maximum Subarray
Platform       : LeetCode
Topic          : Array, Divide and Conquer, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-subarray/submissions/1973604744/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : DP Tabulation
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n - 1][1] = dp[n - 1][0] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i][1] = max(nums[i], nums[i] + dp[i + 1][1]);
            dp[i][0] = max(dp[i + 1][0], dp[i][1]);
        }

        return dp[0][0];
    }
};
