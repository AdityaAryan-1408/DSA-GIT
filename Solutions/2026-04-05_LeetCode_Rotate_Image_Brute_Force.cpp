/*

Problem Name   : Rotate Image
Platform       : LeetCode
Topic          : Array, Math, Matrix
Problem Link   : https://leetcode.com/problems/rotate-image/submissions/1969904069/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Brute Force
Time           : O(N^2)
Space          : O(1)

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> check = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                check[i][j] = matrix[n - j - 1][i];
            }
        }
        matrix = check;
    }
};
