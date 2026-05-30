/*

Problem Name   : Palindromic Substrings
Platform       : LeetCode
Topic          : Two Pointers, String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/palindromic-substrings/submissions/2017413117/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-30
Approach       : Memoization
Time           : O(N ^ 2)
Space          : O(N ^ 2)

*/

class Solution {
public:
    vector<vector<int>> dp;
    bool check(string& s, int i, int j) {
        if (i > j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = check(s, i + 1, j - 1);
        return dp[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};

// TC = O(N ^ 2)
// SC = O(N ^ 2)
