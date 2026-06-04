/*

Problem Name   : Decode Ways
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/decode-ways/submissions/2022078224/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Tabulation
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // dp[i] = number of ways to decode string from index i to n
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < n) {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }
        return dp[0];
    }
};
