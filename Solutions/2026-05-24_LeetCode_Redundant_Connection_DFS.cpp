/*

Problem Name   : Redundant Connection
Platform       : LeetCode
Topic          : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
Problem Link   : https://leetcode.com/problems/redundant-connection/submissions/2011411471/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-24
Approach       : DFS
Time           : O(N^2)
Space          : O(N)

*/

class Solution {
public:
    bool DFS(unordered_map<int, vector<int>>& adj, int u, int v,
             vector<bool>& visited) {
        visited[u] = true;

        if (u == v)
            return true;
        for (int& n : adj[u]) {
            if (visited[n])
                continue;
            if (DFS(adj, n, v, visited))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n, false);
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                DFS(adj, u, v, visited)) {
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
