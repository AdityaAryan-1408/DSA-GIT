/*

Problem Name   : Palindromic Substrings
Platform       : LeetCode
Topic          : Two Pointers, String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/palindromic-substrings/submissions/2017413117/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-30
Approach       : Bottom Up
Time           : O(N ^ 2)
Space          : O(N ^ 2)

*/

class Solution {
public:
    int countSubstrings(string& s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (i == j)
                    dp[i][j] = true;
                else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};

// TC = O(N ^ 2)
// SC = O(N ^ 2)
