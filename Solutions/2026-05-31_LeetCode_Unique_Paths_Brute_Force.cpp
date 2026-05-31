/*

Problem Name   : Unique Paths
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Combinatorics
Problem Link   : https://leetcode.com/problems/unique-paths/submissions/2018312690/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-31
Approach       : Brute Force
Time           : O(N ^ 2)
Space          : O(1)

*/

class Solution {
public:
    int M, N;
    int helper(int i, int j){
        if(i == M - 1 && j == N - 1){
            return 1;
        }

        if(i >= M || j >= N){
            return 0;
        }

        int down = helper(i + 1, j);
        int right = helper(i, j + 1);
        return down + right;
    }
    int uniquePaths(int m, int n) {
        M = m, N = n;
        return helper(0, 0);
    }
};
