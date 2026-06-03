/*

Problem Name   : Distinct Subsequences
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/distinct-subsequences/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Memoization
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int helper(int i, int j, string& s, string& t) {
        if (j == m)
            return 1;
        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] =
                       helper(i + 1, j + 1, s, t) + helper(i + 1, j, s, t);
        } else {
            return dp[i][j] = helper(i + 1, j, s, t);
        }
    }
    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        dp.assign(n, vector<int>(m, -1));
        return helper(0, 0, s, t);
    }
};
