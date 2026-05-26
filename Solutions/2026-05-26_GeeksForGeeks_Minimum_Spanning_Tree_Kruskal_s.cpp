/*

Problem Name   : Minimum Spanning Tree
Platform       : GeeksForGeeks
Topic          : Graph Theory, Minimum Spanning Tree
Problem Link   : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-26
Approach       : Kruskal's
Time           : O(ElogE)
Space          : O(V+ E)

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
	int Vertices;
	int kruskals(vector<vector<int>> &vec) {
	    DSU dsu(Vertices);
		int sum = 0;
		for (auto &temp : vec) {
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
	int spanningTree(int V, vector<vector<int>> & edges) {
	    Vertices = V;
		vector<vector<pair<int, int>> > adj(V);
		for (auto &edge : edges) {
			int u = edge[0], v = edge[1], wt = edge[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		
		vector<vector<int>> vec;
		for (int u = 0; u < V; u++) {
			for (auto &temp : adj[u]) {
				int v = temp.first;
				int wt = temp.second;
				vec.push_back({u, v, wt});
			}
		}
		auto comp = [&](vector<int> &a, vector<int>&b) {
			return a[2] < b[2];
		};
		sort(vec.begin(), vec.end(), comp);
		return kruskals(vec);
	}
};

// TC = O(ElogE)
// SC = O(V + E)
