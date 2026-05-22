/*

Problem Name   : Surrounded Regions
Platform       : LeetCode
Topic          : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
Problem Link   : https://leetcode.com/problems/surrounded-regions/submissions/2009839472/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-22
Time           : O(N) + O(4 * N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int n, m;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<char>>& board) {
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> res;
        n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            if (!visited[0][j] && board[0][j] == 'O') {
                dfs(0, j, visited, board);
            }
            if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, visited, board);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                dfs(i, 0, visited, board);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, visited, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
