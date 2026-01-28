/*

Problem Name   : Shortest Distance in a Binary Maze
Platform       : GeeksForGeeks
Topic          : Graphs
Problem Link   : https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-28

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestPath(vector<vector<int>>& grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();

        if (source == destination) return 0;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[source.first][source.second] = 0;
        q.push(source);

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newR = r + delRow[i];
                int newC = c + delCol[i];

                if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                    grid[newR][newC] == 1 &&
                    dist[newR][newC] > dist[r][c] + 1) {
                    dist[newR][newC] = dist[r][c] + 1;

                    if (newR == destination.first && newC == destination.second)
                        return dist[newR][newC];

                    q.push({newR, newC});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    /*
    We solve this using Dijkstra's algorithm. Initially will maintain a distance array to keep track of the minimum 
    distance to reach each cell, which will have source as 0 and every other cell as infinity. 
    We will also maintain a priority queue to traverse the cells based on minimum distance. However since every cell is
    having a distance of 1, every next cell is increasing by a unit distance, making them sorted automatically thus we can 
    also use a normal queue here. Therfore saving the extra log factor of priority queue.
    */
    return 0;
}