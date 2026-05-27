/*

Problem Name   : Topological Sort
Platform       : GeeksForGeeks
Topic          : Graph Theory, Topological Sort, Breadth-First Search, Depth-First Search
Problem Link   : https://www.geeksforgeeks.org/problems/topological-sort/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-27
Approach       : Kahn's Algorithm
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for (auto &edge : edges) {
			adj[edge[0]].push_back(edge[1]);
		}
		vector<int>inDegree(V);
		for (int u = 0 ; u < V; u++) {
			for (int &v : adj[u]) {
				inDegree[v]++;
			}
		}
		
		queue<int>q;
		for (int i = 0; i<V; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}
		
		vector<int>res;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			res.push_back(u);
			for (int &v : adj[u]) {
				inDegree[v]--;
				if (inDegree[v] == 0)
					q.push(v);
			}
		}
		return res;
	}
};
