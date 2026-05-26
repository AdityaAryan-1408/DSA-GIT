/*

Problem Name   : Min Cost to Connect All Points
Platform       : LeetCode
Topic          : Array, Union-Find, Graph Theory, Minimum Spanning Tree
Problem Link   : https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/2013759851/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-26
Approach       : Kruskals
Time           : O(N^2 LogN)
Space          : O(N^2)

*/

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int xparent = find(x);
        int yparent = find(y);

        if (xparent == yparent)
            return;
        if (rank[xparent] > rank[yparent]) {
            parent[yparent] = xparent;
        } else if (rank[yparent] > rank[xparent]) {
            parent[xparent] = yparent;
        } else {
            parent[yparent] = xparent;
            rank[xparent]++;
        }
    }
};
class Solution {
public:
    typedef pair<int, int> P;
    int N;
    int kruskals(vector<vector<int>>& vec) {
        DSU dsu(N);
        int sum = 0;
        for (auto& temp : vec) {
            int u = temp[0], v = temp[1], wt = temp[2];
            int parentU = dsu.find(u);
            int parentV = dsu.find(v);

            if (parentU != parentV) {
                dsu.Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    int kruskalsAlgorithm(vector<vector<P>> &adj) {
        vector<vector<int>> vec;
        for (int u = 0; u < N; u++) {
            for (auto& temp : adj[u]) {
                int v = temp.first;
                int wt = temp.second;
                vec.push_back({u, v, wt});
            }
        }
        auto comp = [&](vector<int>& a, vector<int>& b) { return a[2] < b[2]; };
        sort(vec.begin(), vec.end(), comp);
        return kruskals(vec);
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
        return kruskalsAlgorithm(adj);
    }
};

// Takes more time than Prims
