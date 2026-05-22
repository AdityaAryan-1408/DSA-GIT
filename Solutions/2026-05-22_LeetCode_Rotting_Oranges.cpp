/*

Problem Name   : Rotting Oranges
Platform       : LeetCode
Topic          : Array, Breadth-First Search, Matrix
Problem Link   : https://leetcode.com/problems/rotting-oranges/submissions/2009804360/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-22
Time           : O(M * N)
Space          : O(M * N)

*/

class Solution {
public:
    typedef pair<int, int> p;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<p> q;

        int freshCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0)
            return 0;

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;
                for (auto dir : directions) {
                    int newI = i + dir[0];
                    int newJ = j + dir[1];

                    if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
                        grid[newI][newJ] == 1) {
                        grid[newI][newJ] = 2;
                        q.push({newI, newJ});
                        freshCount--;
                    }
                }
            }
            minutes++;
        }
        return freshCount == 0 ? minutes - 1 : -1;
    }
};
