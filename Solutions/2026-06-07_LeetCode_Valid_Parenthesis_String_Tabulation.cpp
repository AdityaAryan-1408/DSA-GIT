/*

Problem Name   : Valid Parenthesis String
Platform       : LeetCode
Topic          : String, Dynamic Programming, Stack, Greedy
Problem Link   : https://leetcode.com/problems/valid-parenthesis-string/submissions/2025496719/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-07
Approach       : Tabulation
Time           : O(N ^ 2)
Space          : O(N ^ 2)

*/

class Solution {
public:
    bool checkValidString(string& s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= dp[i + 1][open + 1];
                    if (open > 0) {
                        isValid |= dp[i + 1][open - 1];
                    }
                    isValid |= dp[i + 1][open];
                } else {
                    if (s[i] == '(') {
                        isValid |= dp[i + 1][open + 1];
                    } else if (open > 0) {
                        isValid |= dp[i + 1][open - 1];
                    }
                }
                dp[i][open] = isValid;
            }
        }

        return dp[0][0];
    }
};
