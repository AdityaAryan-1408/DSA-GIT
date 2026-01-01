/*

Problem Name   : Shortest Path from Source with unit length
Platform       : GeeksForGeeks
Topic          : Graphs, BFS
Problem Link   : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-01

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> adj[V];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        vector<int> ans(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
            ans[i] = dist[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    /*
    Find the shortest path from src to all the nodes of the graph, using BFS
    We store node and distance in queue.
    We declare a distance array of size n + 1, filled with infinity. with source at dist = 0.
    As we reach nodes from BFS, we update the distance by min value of current dist and the previously stores value.
    */
    return 0;
}