/*

Problem Name   : Distinct Subsequences
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/distinct-subsequences/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Space Optimized
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int numDistinct(string& s, string& t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
