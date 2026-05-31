/*

Problem Name   : Unique Paths
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Combinatorics
Problem Link   : https://leetcode.com/problems/unique-paths/submissions/2018312690/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Combination
Time           : O(N ^ 2)
Space          : O(1)

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = min(m - 1, n - 1);
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};
