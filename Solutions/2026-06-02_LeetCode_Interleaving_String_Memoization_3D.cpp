/*

Problem Name   : Interleaving String
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/interleaving-string/submissions/2020100051/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Memoization 3D
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    int m, n, N;
    vector<vector<vector<int>>> dp;
    bool helper(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (i == m && j == n && k == N)
            return true;

        if (k >= N)
            return false;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        bool result = false;
        if (s1[i] == s3[k]) {
            result = helper(i + 1, j, k + 1, s1, s2, s3);
        }
        if (result)
            return dp[i][j][k] = result;

        if (s2[j] == s3[k]) {
            result = helper(i, j + 1, k + 1, s1, s2, s3);
        }
        return dp[i][j][k] = result;
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        m = s1.size(), n = s2.size(), N = s3.size();
        dp.assign(m + 1, vector<vector<int>>(n + 1, vector<int>(N + 1, -1)));
        return helper(0, 0, 0, s1, s2, s3);
    }
};
