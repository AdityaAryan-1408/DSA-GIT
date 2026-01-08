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
    /*
    This algo doesnt work with graphs that have a negative cycle or edge with negative weight. Because it goes into an infinite
    loop
    Dijkstra's Algo can be implemented using Queue, Priority Queue, and set data struture. However the Queue takes the 
    most time with PQ taking less and Set being the fastest. 

    Using Priority Queue.
    Step 1. Have a distance array. Assign source node with 0 and everything else with Infinity.
    Step 2. Keep a min heap which keeps the min value at top. We put the src dist and its node 0 in pq. in the order {dist, node}
    Step 3. Remove 0 from pq and move to its neightbours with updating the distance array with min distance
    between current distance and previous distance.

    TC = O()
    This approach gives TLE in GFG.
    */
    return 0;
}