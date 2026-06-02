/*

Problem Name   : Longest Increasing Path in a Matrix
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Memoization, Matrix
Problem Link   : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/2019900609/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-02
Approach       : Memoization
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    int path(vector<vector<int>>& mat, int i, int j, int prev) {
        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;
        if (mat[i][j] <= prev)
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = 1 + path(mat, i - 1, j, mat[i][j]);
        int down = 1 + path(mat, i + 1, j, mat[i][j]);
        int left = 1 + path(mat, i, j - 1, mat[i][j]);
        int right = 1 + path(mat, i, j + 1, mat[i][j]);
        return dp[i][j] = max({up, down, left, right});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp.assign(n, vector<int>(m, -1));
        int maxDist = INT_MIN;
        for(int i = 0; i <n; i++){
            for(int j = 0; j< m; j++){
                int dist = path(matrix, i, j, INT_MIN);
                maxDist = max(maxDist, dist);
            }
        }
        return maxDist;
    }
};
