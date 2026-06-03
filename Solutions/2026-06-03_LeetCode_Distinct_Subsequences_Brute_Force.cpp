/*

Problem Name   : Distinct Subsequences
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/distinct-subsequences/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Brute Force
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    int helper(int i, int j, string& s, string& t) {
        if (j == m)
            return 1;
        if (i == n)
            return 0;

        if (s[i] == t[j]) {
            return helper(i + 1, j + 1, s, t) + helper(i + 1, j, s, t);
        } else {
            return helper(i + 1, j, s, t);
        }
    }
    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        return helper(0, 0, s, t);
    }
};
