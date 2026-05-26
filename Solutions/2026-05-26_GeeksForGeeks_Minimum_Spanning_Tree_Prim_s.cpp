/*

Problem Name   : Minimum Spanning Tree
Platform       : GeeksForGeeks
Topic          : Graph Theory, Minimum Spanning Tree
Problem Link   : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-26
Approach       : Prim's
Time           : O(ElogE)
Space          : O(V+ E)

*/

class Solution {
	public:
	typedef pair<int, int> P;
	int spanningTree(int V, vector<vector<int>> & edges) {
		vector<vector<P>> adj(V);
		for (auto &edge : edges) {
			int u = edge[0], v = edge[1], wt = edge[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		
		priority_queue<P, vector<P>, greater<P>> pq;
		pq.push({0, 0});
		vector<bool> inMST(V, false);
		int totalSum = 0;
		
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			int wt = p.first;
			int node = p.second;
			
			if(inMST[node]) continue;
			
			inMST[node] = true;
			totalSum += wt;
			for(auto &tmp : adj[node]){
			    int neighbor = tmp.first;
			    int neighborWt = tmp.second;
			    if(!inMST[neighbor]){
			        pq.push({neighborWt, neighbor});
			    }
			}
		}
		return totalSum;
		
	}
};

// TC = O(ElogV)
// SC = O(V + E)
