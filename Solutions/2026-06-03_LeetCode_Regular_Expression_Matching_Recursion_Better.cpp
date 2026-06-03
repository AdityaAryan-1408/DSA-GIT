/*

Problem Name   : Regular Expression Matching
Platform       : LeetCode
Topic          : String, Dynamic Programming, Recursion
Problem Link   : https://leetcode.com/problems/regular-expression-matching/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Recursion - Better
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    bool helper(string &s, string &p, int i, int j) {
        if (j == m) {
            return i == n;
        }

        bool firstMatch = (i < n && (p[j] == s[i] || p[j] == '.'));
        if (j + 1 < m && p[j + 1] == '*') {
            bool notTake = helper(s, p, i, j + 2);
            bool take = firstMatch && helper(s, p, i + 1, j);

            return take || notTake;
        }
        return firstMatch && helper(s, p, i + 1, j + 1);
    }
    bool isMatch(string &s, string &p) {
        n = s.size(), m = p.size();
        return helper(s, p, 0, 0);
    }
};
