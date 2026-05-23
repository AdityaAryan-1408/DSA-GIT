/*

Problem Name   : Number of Connected Components
Platform       : Other
Topic          : Deapth-First Search, Breadth-First Search, Union Find, Graph Theory
Problem Link   : https://neetcode.io/problems/count-connected-components/history?submissionIndex=0
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-23
Approach       : BFS
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
   public:
    void BFS(vector<vector<int>>& adj, vector<bool>& visit, int node) {
        queue<int> q;
        q.push(node);
        visit[node] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nei : adj[cur]) {
                if (!visit[nei]) {
                    visit[nei] = true;
                    q.push(nei);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                BFS(adj, visit, node);
                res++;
            }
        }
        return res;
    }
};
