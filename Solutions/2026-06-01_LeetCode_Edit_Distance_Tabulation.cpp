/*

Problem Name   : Edit Distance
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/edit-distance/submissions/2019028470/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Tabulation
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int minDistance(string& a, string& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int ins = 1 + dp[i][j - 1];
                    int del = 1 + dp[i - 1][j];
                    int rep = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min({ins, del, rep});
                }
            }
        }
        return dp[n][m];
    }
};
