/*

Problem Name   : Max Area of Island
Platform       : LeetCode
Topic          : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
Problem Link   : https://leetcode.com/problems/max-area-of-island/submissions/2007140785/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-19
Approach       : BFS
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int i, int j) {
        int count = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;
        while (!q.empty()) {
            auto [f, s] = q.front();
            q.pop();

            for (auto& d : directions) {
                int newI = f + d[0];
                int newJ = s + d[1];

                if (newI < 0 || newI >= n || newJ < 0 || newJ >= m ||
                    grid[newI][newJ] == 0) {
                    continue;
                } else if (grid[newI][newJ] == -1) {
                    continue;
                } else {
                    q.push({newI, newJ});
                    grid[newI][newJ] = -1;
                    count++;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxArea = 0;
        int area = 0;
        for(int i = 0;i <n; i++){
            for(int j = 0; j <m; j++){
                if(grid[i][j] == 1){
                    area = bfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
