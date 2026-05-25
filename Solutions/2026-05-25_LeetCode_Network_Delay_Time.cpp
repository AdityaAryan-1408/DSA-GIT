/*

Problem Name   : Network Delay Time
Platform       : LeetCode
Topic          : Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path
Problem Link   : https://leetcode.com/problems/network-delay-time/submissions/2012793311/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-25
Time           : O((V + E)logE)
Space          : O(V + E)

*/

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<vector<pair<int, int>>> adj(V + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }
        vector<int> result(V + 1, INT_MAX);
        result[src] = 0;

        pq.push({0, src});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                if (d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        return result;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time = dijkstra(n, times, k);
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, time[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
