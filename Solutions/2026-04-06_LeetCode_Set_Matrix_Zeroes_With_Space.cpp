/*

Problem Name   : Set Matrix Zeroes
Platform       : LeetCode
Topic          : Array, Hash Table, Matrix
Problem Link   : https://leetcode.com/problems/set-matrix-zeroes/submissions/1970421629/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06
Approach       : With Space
Time           : O(M * N)
Space          : O(1)

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
