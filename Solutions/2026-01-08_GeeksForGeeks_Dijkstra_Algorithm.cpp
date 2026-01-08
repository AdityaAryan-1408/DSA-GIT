/*

Problem Name   : Dijkstra Algorithm
Platform       : GeeksForGeeks
Topic          : Graphs
Problem Link   : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int s) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(V, INT_MAX);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, s});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dis > dist[node]) continue;
            for (auto it : adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution s;

    return 0;
}