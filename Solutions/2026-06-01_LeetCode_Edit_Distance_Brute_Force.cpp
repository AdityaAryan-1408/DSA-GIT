/*

Problem Name   : Edit Distance
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/edit-distance/submissions/2019028470/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Brute Force
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    int helper(int i, int j, string &a, string &b){
        if(i >= n) return m - j;
        if(j >= m) return n - i;

        int take = 0, notTake = 0;
        if(a[i] == b[j]){
            return helper(i + 1, j + 1, a, b);
        }else{
            int ins = 1 + helper(i, j + 1, a, b);
            int del = 1 + helper(i + 1, j, a, b);
            int rep = 1 + helper(i + 1, j + 1, a, b);
            return min({ins, del, rep});
        }
    }
    int minDistance(string &word1, string &word2) {
        n = word1.size(), m = word2.size();
        return helper(0, 0, word1, word2);
    }
};
