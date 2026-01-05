/*

Problem Name   : Shortest path in Directed Acyclic Graph
Platform       : GeeksForGeeks
Topic          : Graphs, TopoSort
Problem Link   : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-05

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis,
                  stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (dist[node] == INT_MAX) continue;
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

int main() {
    Solution s;
    /*
    Shortest path in DAG but the edges have weight.
    In the adjacency list, instead of storing the neighbours only, we will
    store a pair of neighbours and their edge weight.

    Step 1: Do the toposort for this graph, and maintain a visited array.
    Step 2: Take the nodes out of stack and relax the edges. We declare a
    distance array and mark the cells with infinity. But make the source
    node as 0. Then for all the adjacent nodes of source node, we go and
    update the current value in dist array with current dist + min distance
    of already present value and value of distance in the adj list. in the
    dist array

    */
    return 0;
}