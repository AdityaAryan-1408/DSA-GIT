/*

Problem Name   : Max Area of Island
Platform       : LeetCode
Topic          : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
Problem Link   : https://leetcode.com/problems/max-area-of-island/submissions/2007140785/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-19
Approach       : DFS
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = -1;
        int area = 1;
        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            area += dfs(grid, ni, nj);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxArea = 0;
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
