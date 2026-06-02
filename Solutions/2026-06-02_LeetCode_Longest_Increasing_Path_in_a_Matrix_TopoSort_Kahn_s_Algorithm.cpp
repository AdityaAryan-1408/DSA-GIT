/*

Problem Name   : Longest Increasing Path in a Matrix
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Memoization, Matrix
Problem Link   : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/2019900609/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-02
Approach       : TopoSort - Kahn's Algorithm
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> indegree(rows, vector<int>(cols, 0));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                for (auto& dir : directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                        matrix[nr][nc] < matrix[r][c]) {
                        indegree[r][c]++;
                    }
                }
            }
        }

        queue<pair<int, int>>q;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(indegree[r][c] == 0){
                    q.push({r, c});
                }
            }
        }

        int LIP = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [r, c] = q.front();
                q.pop();
                for(auto &dir : directions){
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 &&
                        nc < cols && matrix[nr][nc] > matrix[r][c]) {
                        if (--indegree[nr][nc] == 0) {
                            q.push({nr, nc});
                        }
                    }
                }
            }
            LIP++;
        }
        return LIP;
    }
};
