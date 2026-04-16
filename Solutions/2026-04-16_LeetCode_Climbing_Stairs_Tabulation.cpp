/*

Problem Name   : Climbing Stairs
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Memoization
Problem Link   : https://leetcode.com/problems/climbing-stairs/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Tabulation
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(n == 1 || n == 2) return n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        return helper(n, dp);
    }
};
