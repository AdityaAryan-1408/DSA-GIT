/*

Problem Name   : Set Matrix Zeroes
Platform       : LeetCode
Topic          : Array, Hash Table, Matrix
Problem Link   : https://leetcode.com/problems/set-matrix-zeroes/submissions/1970421629/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06
Approach       : Optimal
Time           : O(M * N)
Space          : O(1)

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0) {
                firstRow = true;
                break;
            }
        }
        for (int row = 0; row < m; row++) {
            if (matrix[row][0] == 0) {
                firstCol = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
