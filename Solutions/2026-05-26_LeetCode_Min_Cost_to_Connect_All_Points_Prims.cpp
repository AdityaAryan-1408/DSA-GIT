/*

Problem Name   : Min Cost to Connect All Points
Platform       : LeetCode
Topic          : Array, Union-Find, Graph Theory, Minimum Spanning Tree
Problem Link   : https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/2013759851/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-26
Approach       : Prims
Time           : O(N^2 LogN)
Space          : O(N^2)

*/

class Solution {
public:
    typedef pair<int, int> P;
    int N;
    int primsAlgorithm(vector<vector<pair<int, int>>>& adj) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(N, false);
        int totalSum = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;

            if (inMST[node])
                continue;

            inMST[node] = true;
            totalSum += wt;
            for (auto& tmp : adj[node]) {
                int neighbor = tmp.first;
                int neighborWt = tmp.second;
                if (!inMST[neighbor]) {
                    pq.push({neighborWt, neighbor});
                }
            }
        }
        return totalSum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        N = points.size();
        vector<vector<P>> adj(N);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int distance = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, distance});
                adj[j].push_back({i, distance});
            }
        }
        return primsAlgorithm(adj);
    }
};
