/*

Problem Name   : Rotate Image
Platform       : LeetCode
Topic          : Array, Math, Matrix
Problem Link   : https://leetcode.com/problems/rotate-image/submissions/1969904069/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Optimal
Time           : O(N^2)
Space          : O(1)

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
