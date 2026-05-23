/*

Problem Name   : Graph is Tree or Not
Platform       : GeeksForGeeks
Topic          : Graphs, Tree, Breadth-First Search, Depth-First Search
Problem Link   : https://www.geeksforgeeks.org/problems/is-it-a-tree/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-23
Approach       : BFS
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
	public:
	int isTree(int n, int m, vector<vector<int>> &edges) {
		if (m > n - 1) {
			return 0;
		}
		
		vector<vector<int>> adj(n);
		for (auto edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}
		
		unordered_set<int>visited;
		queue<pair<int, int>>q;
		
		q.push({0, -1});
		visited.insert(0);
		
		while(!q.empty()){
		    auto [node, parent] = q.front();
		    q.pop();
		    for(int n : adj[node]){
		        if(n == parent) continue;
		        
		        if(visited.count(n)) return false;
		        
		        visited.insert(n);
		        q.push({n, node});
		    }
		}
		
		return visited.size() == n;
	}
};
