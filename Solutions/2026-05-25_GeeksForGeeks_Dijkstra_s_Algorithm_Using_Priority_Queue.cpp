/*

Problem Name   : Dijkstra's Algorithm
Platform       : GeeksForGeeks
Topic          : Graph Theory, Shortest Path
Problem Link   : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-25
Approach       : Using Priority Queue
Time           : O((V + E) log E)
Space          : O(V + E)

*/

class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		
		vector<vector<pair<int, int>> >adj(V);
		for (auto &edge : edges) {
			int u = edge[0], v = edge[1], wt = edge[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		vector<int> result(V, INT_MAX);
		result[src] = 0;
		
		pq.push({0, src});
		while (!pq.empty()) {
			int d = pq.top().first;
			int node = pq.top().second;
			pq.pop();
			
			for (auto &vec : adj[node]) {
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
};
