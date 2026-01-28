/*

Problem Name   : Shortest Path in Binary Matrix
Platform       : LeetCode
Topic          : Graphs
Problem Link   : https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-28

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        dist[0][0] = 1;
        q.push({0, 0});

        vector<int> delRow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> delCol = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1) return dist[r][c];

            for (int i = 0; i < 8; i++) {
                int newR = r + delRow[i];
                int newC = c + delCol[i];

                if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                    grid[newR][newC] == 0 &&
                    dist[newR][newC] > dist[r][c] + 1) {
                    dist[newR][newC] = dist[r][c] + 1;
                    q.push({newR, newC});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}