/*

Problem Name   : Minimum Spanning Tree
Platform       : GeeksForGeeks
Topic          : Graph Theory, Minimum Spanning Tree
Problem Link   : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-26
Approach       : Prims with Parent Vector
Time           : O(ElogE)
Space          : O(V+ E)

*/

class Solution {
	public:
	typedef vector<int> T;
	
	int spanningTree(int V, vector<vector<int>> &edges) {
		vector<vector<pair<int, int>> > adj(V);
		for (auto &edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		
		// {wt, node, parent}
		priority_queue<T, vector<T>, greater<T>> pq;
		
		pq.push({0, 0, -1});
		
		vector<bool> inMST(V, false);
		vector<int> parent(V, -1);
		
		int totalSum = 0;
		
		while (!pq.empty()) {
			
			auto curr = pq.top();
			pq.pop();
			
			int wt = curr[0];
			int node = curr[1];
			int par = curr[2];
			
			if (inMST[node])
				continue;
			
			inMST[node] = true;
			
			totalSum += wt;
			parent[node] = par;
			
			for (auto &tmp : adj[node]) {
				
				int neighbor = tmp.first;
				int neighborWt = tmp.second;
				
				if (!inMST[neighbor]) {
					pq.push({neighborWt, neighbor, node});
				}
			}
		}
		
		return totalSum;
	}
};
