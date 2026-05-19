/*

Problem Name   : Clone Graph
Platform       : LeetCode
Topic          : Hash Table, Depth-First Search, Breadth-First Search, Graph Theory
Problem Link   : https://leetcode.com/problems/clone-graph/description/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-19
Approach       : BFS
Time           : O(V + E)
Space          : O(V + E)

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void BFS(queue<Node*>& q) {
        while (!q.empty()) {
            Node* node = q.front();
            Node* clone_node = mp[node];
            q.pop();
            for (Node* n : node->neighbors) {
                if (mp.find(n) == mp.end()) {
                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);
                    q.push(n);
                } else {
                    clone_node->neighbors.push_back(mp[n]);
                }
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        mp.clear();
        Node* clone = new Node(node->val);
        mp[node] = clone;
        queue<Node*> q;
        q.push(node);
        BFS(q);
        return clone;
    }
};
