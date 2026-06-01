/*

Problem Name   : Edit Distance
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/edit-distance/submissions/2019028470/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Memoization
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int helper(int i, int j, string &a, string &b){
        if(i >= n) return m - j;
        if(j >= m) return n - i;

        if(dp[i][j] != -1) return dp[i][j];
        int take = 0, notTake = 0;
        if(a[i] == b[j]){
            return dp[i][j] = helper(i + 1, j + 1, a, b);
        }else{
            int ins = 1 + helper(i, j + 1, a, b);
            int del = 1 + helper(i + 1, j, a, b);
            int rep = 1 + helper(i + 1, j + 1, a, b);
            return dp[i][j] = min({ins, del, rep});
        }
    }
    int minDistance(string &word1, string &word2) {
        n = word1.size(), m = word2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, word1, word2);
    }
};
