/*

Problem Name   : Redundant Connection
Platform       : LeetCode
Topic          : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
Problem Link   : https://leetcode.com/problems/redundant-connection/submissions/2011411471/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-24
Approach       : BFS
Time           : O(N^2)
Space          : O(N)

*/

class Solution {
public:
    bool BFS(unordered_map<int, vector<int>>& adj, int u, int v,
             vector<bool>& visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == v)
                return true;
            for (int n : adj[node]) {
                if (visited[n])
                    continue;
                visited[n] = true;
                q.push(n);
            }
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
                BFS(adj, u, v, visited)) {
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
