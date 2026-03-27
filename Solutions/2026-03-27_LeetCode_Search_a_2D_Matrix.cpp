/*

Problem Name   : Search a 2D Matrix
Platform       : LeetCode
Topic          : Array, Binary Search, Matrix
Problem Link   : https://leetcode.com/problems/search-a-2d-matrix/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-27
Time           : O(log (M * N))
Space          : O(1)

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row =
                mid / m; // To get the hypothetical 1D matrix rep of 2D matrix
            int col =
                mid % m; // To get the hypothetical 1D matrix rep of 2D matrix
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
