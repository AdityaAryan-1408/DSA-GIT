/*

Problem Name   : Course Schedule
Platform       : LeetCode
Topic          : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
Problem Link   : https://leetcode.com/problems/course-schedule/submissions/2009983495/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-22
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
public:
    bool topoSortCheck(unordered_map<int, vector<int>>& adj, int n,
                       vector<int>& indegree) {
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                cnt++;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int a = vec[0], b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoSortCheck(adj, numCourses, indegree);
    }
};
