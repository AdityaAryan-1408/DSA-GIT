/*

Problem Name   : Interleaving String
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/interleaving-string/submissions/2020100051/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Memoization 2d
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    int m, n, N;
    vector<vector<int>> dp;
    bool helper(int i, int j, string& s1, string& s2, string& s3) {
        if (i == m && j == n && i + j == N)
            return true;

        if (i + j >= N)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];
        bool result = false;
        if (s1[i] == s3[i + j]) {
            result = helper(i + 1, j, s1, s2, s3);
        }
        if (result)
            return dp[i][j] = result;

        if (s2[j] == s3[i + j]) {
            result = helper(i, j + 1, s1, s2, s3);
        }
        return dp[i][j] = result;
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        m = s1.size(), n = s2.size(), N = s3.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, s1, s2, s3);
    }
};
