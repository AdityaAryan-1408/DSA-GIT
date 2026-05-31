/*

Problem Name   : Unique Paths
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Combinatorics
Problem Link   : https://leetcode.com/problems/unique-paths/submissions/2018312690/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Memoization
Time           : O(N ^ 2)
Space          : O(1)

*/

class Solution {
public:
    int M, N;
    int helper(int i, int j, vector<vector<int>>&dp){
        if(i == M - 1 && j == N - 1){
            return 1;
        }

        if(i >= M || j >= N){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int down = helper(i + 1, j, dp);
        int right = helper(i, j + 1, dp);
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        M = m, N = n;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, dp);
    }
};
