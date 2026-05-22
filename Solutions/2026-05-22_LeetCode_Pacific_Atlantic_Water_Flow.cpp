/*

Problem Name   : Pacific Atlantic Water Flow
Platform       : LeetCode
Topic          : Array, Depth-First Search, Breadth-First Search, Matrix
Problem Link   : https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/2009835338/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-22
Time           : O( 2 * M * N)
Space          : O(2 * M * N)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void DFS(vector<vector<int>>& heights, int i, int j, int prevCell,
             vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }

        if (heights[i][j] < prevCell || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        for(auto dir : directions){
            int newI = i + dir[0];
            int newJ = j + dir[1];

            DFS(heights, newI, newJ, heights[i][j], visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;

        vector<vector<bool>> pacificVisited(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVisited(n, vector<bool>(m, false));

        for (int j = 0; j < m; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited);
            DFS(heights, n - 1, j, INT_MIN, atlanticVisited);
        }

        for (int i = 0; i < n; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited);
            DFS(heights, i, m - 1, INT_MIN, atlanticVisited);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
