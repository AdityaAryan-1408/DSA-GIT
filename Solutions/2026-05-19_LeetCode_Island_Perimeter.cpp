/*

Problem Name   : Island Perimeter
Platform       : LeetCode
Topic          : Array, Depth-First Search, Breadth-First Search, Matrix
Problem Link   : https://leetcode.com/problems/island-perimeter/submissions/2007082906/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-19
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    int n, m;
    int perimeter;

    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        while (!q.empty()) {
            auto [f, s] = q.front();
            q.pop();

            for (auto& d : dir) {
                int newI = f + d[0];
                int newJ = s + d[1];

                if (newI < 0 || newI >= n || newJ < 0 || newJ >= m ||
                    grid[newI][newJ] == 0) {
                    perimeter++;
                } else if (grid[newI][newJ] == -1) {
                    continue;
                } else {
                    q.push({newI, newJ});
                    grid[newI][newJ] = -1;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        perimeter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};
