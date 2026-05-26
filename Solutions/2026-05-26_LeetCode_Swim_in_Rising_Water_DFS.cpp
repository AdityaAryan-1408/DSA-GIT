/*

Problem Name   : Swim in Rising Water
Platform       : LeetCode
Topic          : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix
Problem Link   : https://leetcode.com/problems/swim-in-rising-water/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-26
Approach       : DFS
Time           : O(N^2 logN)
Space          : O(N^2)

*/

class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r,
             int c, int t) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid.size() ||
            visit[r][c] || grid[r][c] > t) {
            return false;
        }
        if (r == grid.size() - 1 && c == grid.size() - 1) {
            return true;
        }
        visit[r][c] = true;
        return dfs(grid, visit, r + 1, c, t) || dfs(grid, visit, r - 1, c, t) ||
               dfs(grid, visit, r, c + 1, t) || dfs(grid, visit, r, c - 1, t);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        int minH = grid[0][0], maxH = grid[0][0];
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                maxH = max(maxH, grid[row][col]);
                minH = min(minH, grid[row][col]);
            }
        }

        for (int t = minH; t < maxH; t++) {
            if (dfs(grid, visit, 0, 0, t)) {
                return t;
            }
            for (int r = 0; r < n; r++) {
                fill(visit[r].begin(), visit[r].end(), false);
            }
        }
        return maxH;
    }
};
