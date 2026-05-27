/*

Problem Name   : Alien Dictionary
Platform       : LeetCode
Topic          : Graph Theory, Breadth-First Search, Depth-First Search, Topological Sort
Problem Link   : https://www.geeksforgeeks.org/problems/alien-dictionary/1
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-27
Approach       : Optimal
Time           : O(NL+K^2)
Space          : O(K + E)

*/

class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> &adj) {
		vector<int> indegree(V, 0);
		for (int i = 0; i < V; i++)
			for (auto it : adj[i])
				indegree[it]++;
		
		queue<int> q;
		for (int i = 0; i < V; i++)
			if (indegree[i] == 0)
				q.push(i);
		
		vector<int> res;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (auto it : adj[node]) {
				if (--indegree[it] == 0)
					q.push(it);
			}
		}
		return res;
	}
	
	string findOrder(vector<string> &words) {
		unordered_set<char> st;
		for (auto &w : words)
			for (char c : w)
				st.insert(c);
		
		unordered_map<char, int> id;
		unordered_map<int, char> rid;
		int idx = 0;
		for (char c : st) {
			id[c] = idx;
			rid[idx] = c;
			idx++;
		}
		
		int K = idx;
		vector<vector<int>> adj(K);
		
		for (int i = 0; i < words.size() - 1; i++) {
			string &s1 = words[i];
			string &s2 = words[i + 1];
			
			int len = min(s1.size(), s2.size());
			bool found = false;
			
			for (int j = 0; j < len; j++) {
				if (s1[j] != s2[j]) {
					adj[id[s1[j]]].push_back(id[s2[j]]);
					found = true;
					break;
				}
			}
			
			if (!found && s1.size() > s2.size())
				return "";
		}
		
		vector<int> topo = topoSort(K, adj);
		if (topo.size() != K)
			return "";
		
		string ans;
		for (int it : topo)
			ans += rid[it];
		
		return ans;
	}
};
