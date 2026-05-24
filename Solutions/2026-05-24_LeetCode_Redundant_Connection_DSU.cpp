/*

Problem Name   : Redundant Connection
Platform       : LeetCode
Topic          : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
Problem Link   : https://leetcode.com/problems/redundant-connection/submissions/2011411471/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-24
Approach       : DSU
Time           : O(N^2)
Space          : O(N)

*/

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int xparent = find(x);
        int yparent = find(y);

        if (xparent == yparent)
            return;
        if (rank[xparent] > rank[yparent]) {
            parent[yparent] = xparent;
        } else if (rank[yparent] > rank[xparent]) {
            parent[xparent] = yparent;
        } else {
            parent[yparent] = xparent;
            rank[xparent]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            if (dsu.find(u) == dsu.find(v))
                return edge;

            dsu.Union(u, v);
        }
        return {};
    }
};

// TC = O(n * alpha(n))
