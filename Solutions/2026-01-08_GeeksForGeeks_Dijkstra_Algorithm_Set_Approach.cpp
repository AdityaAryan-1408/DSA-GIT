/*

Problem Name   : Dijkstra Algorithm Set Approach
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
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);

        dist[s] = 0;
        st.insert({0, s});

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int dis = it.first;
            int node = it.second;

            for (auto& edge : adj[node]) {
                int adjNode = edge.first;
                int edgeWeight = edge.second;

                if (dis + edgeWeight < dist[adjNode]) {
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution s;
    /*
    Set approach. Set by default stores the smallest value at top and in ascending order with no duplicates.
    We set up the set in the same way as PQ and a dist array. The difference is that when a node is encountered
    and it was previously visited, i.e not having inf as value in dist then we can say that a {dist, node} must be 
    present in the set, in this case we will remove the previous value which has no point in being in the set and insert
    the new value. This deletion did not happen in PQ which make it traverse the same node multiple times causing TLE.
    However this process in set doesnt improve the TC in a significant way. It depends on various cases like size of graph and
    other factors. 
    */
    return 0;
}