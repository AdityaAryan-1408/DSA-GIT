/*

Problem Name   : Longest Common Subsequence
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-common-subsequence/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Memoization
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int helper(string& a, string& b, int i, int j) {
        if (i >= n || j >= m) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j]) {
            return dp[i][j] = 1 + helper(a, b, i + 1, j + 1);
        }

        return dp[i][j] = max(helper(a, b, i + 1, j), helper(a, b, i, j + 1));
    }
    int longestCommonSubsequence(string a, string b) {
        n = a.size(), m = b.size();
        dp.assign(n, vector<int>(m, -1));
        return helper(a, b, 0, 0);
    }
};
