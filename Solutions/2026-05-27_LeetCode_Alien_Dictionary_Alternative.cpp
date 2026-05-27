/*

Problem Name   : Alien Dictionary
Platform       : LeetCode
Topic          : Graph Theory, Breadth-First Search, Depth-First Search, Topological Sort
Problem Link   : https://www.geeksforgeeks.org/problems/alien-dictionary/1
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-27
Approach       : Alternative
Time           : O(NL+K^2)
Space          : O(K + E)

*/

class Solution {
   public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return res;
    }
    string findOrder(vector<string>& words, int N, int K) {
        vector<vector<int>> adj(K);
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (auto it : topo) {
            ans += char(it + 'a');
        }
        return ans;
    }
};
