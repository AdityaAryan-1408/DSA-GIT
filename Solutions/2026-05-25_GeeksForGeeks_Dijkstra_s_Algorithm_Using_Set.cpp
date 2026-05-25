/*

Problem Name   : Dijkstra's Algorithm
Platform       : GeeksForGeeks
Topic          : Graph Theory, Shortest Path
Problem Link   : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-25
Approach       : Using Set
Time           : O((V + E) log E)
Space          : O(V + E)

*/

class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		vector<vector<pair<int, int>> > adj(V);
		for (auto &edge : edges) {
			adj[edge[0]].push_back({edge[1], edge[2]});
			adj[edge[1]].push_back({edge[0], edge[2]});
		}
		
		set<pair<int, int>> st;
		vector<int> result(V, INT_MAX);
		result[src] = 0;
		st.insert({0, src});
		while (!st.empty()) {
			auto vec = *st.begin();
			st.erase(st.begin());
			
			int d = vec.first;
			int node = vec.second;
			
			for (auto &vec: adj[node]) {
				int adjNode = vec.first;
				int wt = vec.second;
				
				if (d + wt < result[adjNode]) {
					if (result[adjNode] != INT_MAX) {
						st.erase({result[adjNode], adjNode});
					}
					
					result[adjNode] = d + wt;
					st.insert({d + wt, adjNode});
				}
			}
		}
		return result;		
	}
};
