/*

Problem Name   : Longest Common Subsequence
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-common-subsequence/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Tabulation
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
