/*

Problem Name   : Graph is Tree or Not
Platform       : GeeksForGeeks
Topic          : Graphs, Tree, Breadth-First Search, Depth-First Search
Problem Link   : https://www.geeksforgeeks.org/problems/is-it-a-tree/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-23
Approach       : DFS
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
	public:
	bool DFS(int node, int parent, unordered_set<int> &visited, vector<vector<int>> &adj) {
		if (visited.count(node)) return false; // if already visited returns > 0
		
		visited.insert(node);
		for (int n : adj[node]) {
			if (n == parent)
				continue;
			
			if (!DFS(n, node, visited, adj))
				return false;
		}
		return true;
		
	}
	int isTree(int n, int m, vector<vector<int>> &edges) {
		if (m > n - 1) {
			return 0;
		}
		
		vector<vector<int>> adj(n);
		// Creating Adjacency List
		for (auto edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}
		
		unordered_set<int>visited;
		if (!DFS(0, -1, visited, adj))
			return false;
		
		return visited.size() == n ? 1 : 0;
	}
};
