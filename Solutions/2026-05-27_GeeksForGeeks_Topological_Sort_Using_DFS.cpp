/*

Problem Name   : Topological Sort
Platform       : GeeksForGeeks
Topic          : Graph Theory, Topological Sort, Breadth-First Search, Depth-First Search
Problem Link   : https://www.geeksforgeeks.org/problems/topological-sort/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-27
Approach       : Using DFS
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
	public:
	void DFS(vector<vector<int>> &adj, int u, vector<bool> &visited, stack<int>&st) {
		visited[u] = true;
		for (int &v : adj[u]) {
			if (!visited[v]) {
				DFS(adj, v, visited, st);
			}
		}
		st.push(u);
	}
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for (auto &edge: edges) {
			adj[edge[0]].push_back(edge[1]);
		}
		stack<int>st;
		vector<bool>visited(V, false);
		for (int i = 0; i<V; i++) {
			if (!visited[i]) {
				DFS(adj, i, visited, st);
			}
		}
		vector<int>res;
		while (!st.empty()) {
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}
};

// TC = O(V + E)
// SC = O(V + E)
