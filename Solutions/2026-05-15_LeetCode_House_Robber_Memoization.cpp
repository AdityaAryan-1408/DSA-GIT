/*

Problem Name   : House Robber
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/house-robber/submissions/2003720947/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15
Approach       : Memoization
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int n;
    int helper(vector<int>& nums, vector<int>& dp) {
        dp[0] = nums[0];
        int pick, notPick;
        for (int i = 1; i < n; i++) {
            pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];

            notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, dp);
    }
};
