/*

Problem Name   : Minimum ASCII Delete Sum for Two Strings
Platform       : LeetCode
Topic          : String, DP
Problem Link   : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j] + s1[i];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        int total = 0;
        for (char c : s1) total += c;
        for (char c : s2) total += c;

        return total - 2 * dp[n][m];
    }
};

int main() {
    Solution s;

    return 0;
}