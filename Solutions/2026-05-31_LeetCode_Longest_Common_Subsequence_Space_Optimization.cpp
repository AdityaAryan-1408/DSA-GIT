/*

Problem Name   : Longest Common Subsequence
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-common-subsequence/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Space Optimization
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int n = a.size(), m = b.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
