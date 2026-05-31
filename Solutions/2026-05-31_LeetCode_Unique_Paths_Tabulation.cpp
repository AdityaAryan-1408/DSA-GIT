/*

Problem Name   : Unique Paths
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Combinatorics
Problem Link   : https://leetcode.com/problems/unique-paths/submissions/2018312690/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Tabulation
Time           : O(N ^ 2)
Space          : O(1)

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int down = 0, right = 0;
                    if (i > 0) {
                        down = dp[i - 1][j];
                    }
                    if (j > 0) {
                        right = dp[i][j - 1];
                    }
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
