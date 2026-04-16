/*

Problem Name   : Min Cost Climbing Stairs
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1980303099/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Memoization
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int helper(vector<int>& cost, int i, vector<int>&dp) {
        if (i >= n)
            return 0;
        if(dp[i] != -1) return dp[i];

        int a = cost[i] + helper(cost, i + 1, dp);
        int b = cost[i] + helper(cost, i + 2, dp);

        return dp[i]=  min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(helper(cost, 0, dp), helper(cost, 1, dp));
    }
};
