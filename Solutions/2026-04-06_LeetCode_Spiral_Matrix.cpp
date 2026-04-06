/*

Problem Name   : Spiral Matrix
Platform       : LeetCode
Topic          : Array, Matrix, Simulation
Problem Link   : https://leetcode.com/problems/spiral-matrix/submissions/1970240984/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        vector<int> res;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> steps = {static_cast<int>(matrix[0].size()),
                             static_cast<int>(matrix.size()) - 1};

        int r = 0, c = -1, d = 0;
        while (steps[d % 2]) {
            for (int i = 0; i < steps[d % 2]; i++) {
                r += directions[d].first;
                c += directions[d].second;
                res.push_back(matrix[r][c]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return res;
    }
};
