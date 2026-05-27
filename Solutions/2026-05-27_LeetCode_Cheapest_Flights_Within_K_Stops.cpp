/*

Problem Name   : Cheapest Flights Within K Stops
Platform       : LeetCode
Topic          : Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path
Problem Link   : https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/2014496008/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-27
Time           : O((K+1)⋅E)
Space          : O(V+E)

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> distance(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& f : flights) {
            int u = f[0], v = f[1], cost = f[2];
            adj[u].push_back({v, cost});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;
        int steps = 0;

        while (!q.empty() && steps <= k) {
            int N = q.size();
            while (N--) {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                for (auto& P : adj[u]) {
                    int v = P.first;
                    int cost = P.second;

                    if (distance[v] > d + cost) {
                        distance[v] = d + cost;
                        q.push({v, d + cost});
                    }
                }
            }
            steps++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
