/*

Problem Name   : Swim in Rising Water
Platform       : LeetCode
Topic          : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix
Problem Link   : https://leetcode.com/problems/swim-in-rising-water/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-26
Approach       : BFS + Binary Search
Time           : O(N^2 logN)
Space          : O(N^2)

*/

class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool reachPossible(vector<vector<int>>& grid, int i, int j, int t,
                       vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] ||
            grid[i][j] > t)
            return false;

        visited[i][j] = true;
        if (i == n - 1 && j == n - 1)
            return true;
        for (auto dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if (reachPossible(grid, newI, newJ, t, visited))
                return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0], r = n * n - 1;

        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (reachPossible(grid, 0, 0, mid, visited)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};

// TC = O(N^2 Log n)
// SC = O(N ^ 2)
