/*

Problem Name   : Jump Game II
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game-ii/submissions/1976080433/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : DP
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int n;
    int helper(int ind, int jumps, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind >= n - 1) {
            return jumps;
        }
        if (dp[ind][jumps] != -1)
            return dp[ind][jumps];
        int mini = INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) {
            mini = min(mini, helper(ind + i, jumps + 1, nums, dp));
        }
        return dp[ind][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, 0, nums, dp);
    }
};
