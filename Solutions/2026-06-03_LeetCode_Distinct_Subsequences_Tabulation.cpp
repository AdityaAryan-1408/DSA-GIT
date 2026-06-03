/*

Problem Name   : Distinct Subsequences
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/distinct-subsequences/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Tabulation
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int numDistinct(string &s, string &t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
