/*

Problem Name   : Longest Palindromic Substring
Platform       : LeetCode
Topic          : Two Pointers, String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-palindromic-substring/submissions/2016369420/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-29
Approach       : Memoization
Time           : O(N^2)
Space          : O(N^2)

*/

class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string& s, int i, int j) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = isPalindrome(s, i + 1, j - 1);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        int maxLen = 0;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                if (isPalindrome(s, i, j)) {
                    maxLen = max(maxLen, len);
                    if (maxLen == len) {
                        ind = i;
                    }
                }
            }
        }
        return s.substr(ind, maxLen);
    }
};
