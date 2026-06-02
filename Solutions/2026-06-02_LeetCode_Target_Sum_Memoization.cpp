/*

Problem Name   : Target Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/target-sum/submissions/2020063647/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Memoization
Time           : O(N * S)
Space          : O(N * S)

*/

class Solution {
public:
    int sum;
    int helper(vector<int>& nums, int target, int i, int curr,
               vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (curr == target)
                return 1;
            return 0;
        }

        if (dp[i][curr + sum] != -1)
            return dp[i][curr + sum];

        int plus = helper(nums, target, i + 1, curr + nums[i], dp);
        int minus = helper(nums, target, i + 1, curr - nums[i], dp);
        return dp[i][curr + sum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));
        return helper(nums, target, 0, 0, dp);
    }
};
