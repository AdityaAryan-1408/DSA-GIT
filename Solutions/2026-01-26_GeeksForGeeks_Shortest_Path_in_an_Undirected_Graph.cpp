/*

Problem Name   : Shortest Path in an Undirected Graph
Platform       : GeeksForGeeks
Topic          : Graphs
Problem Link   : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-26

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> shortestPathForGFG(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n + 1, INT_MAX), parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n] == INT_MAX) return {-1};

        vector<int> path;
        int cur = n;
        while (cur != parent[cur]) {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        path.insert(path.begin(), dist[n]);

        return path;
    }
    vector<int> shortestPathGeneralApproach(int n, int m,
                                            vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& it : adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if (dist[n] == INT_MAX) return {-1};
        vector<int> path;
        int current = n;
        while (current != 1) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Solution s;
    /*
    To solve this, we need to modify Dijkstra's algorithm such that it remembers where we come from to reach
    each node. Initially we will take a PQ and a distance array, this is marked with Infinity. We will also take a 
    parent array to remember the parent of each node. Initially assigned with index value.
    We start with traversing the graph from the source node. And upadte the distance and the parent array as we go.
    After we reach the destination node, we will check if its distance is still infinity, if it is, we return -1 as 
    there is no path. If there is a path, we will backtrack from destination to source using the parent 
    array and store the path in a vector.
    Finally when the traversal is done, we start from the end of the Distance array, which will have n or last node.
    Using the parent array we find from where we came to this node, so parent[n] gives the previous node. We keep doing this
    until we reach the source node. This will give us the path in reverse order, so we reverse the vector before returning it.
    */
    return 0;
}