/*

Problem Name   : Interleaving String
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/interleaving-string/submissions/2020100051/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Recursion
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    int m, n, N;
    bool helper(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (i == m && j == n && k == N)
            return true;

        if (k >= N)
            return false;

        bool result = false;
        if (s1[i] == s3[k]) {
            result = helper(i + 1, j, k + 1, s1, s2, s3);
        }
        if (result)
            return result;
        if (s2[j] == s3[k]) {
            result = helper(i, j + 1, k + 1, s1, s2, s3);
        }
        return result;
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        m = s1.size(), n = s2.size(), N = s3.size();
        return helper(0, 0, 0, s1, s2, s3);
    }
};
