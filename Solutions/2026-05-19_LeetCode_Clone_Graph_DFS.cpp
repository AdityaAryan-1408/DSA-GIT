/*

Problem Name   : Clone Graph
Platform       : LeetCode
Topic          : Hash Table, Depth-First Search, Breadth-First Search, Graph Theory
Problem Link   : https://leetcode.com/problems/clone-graph/description/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-19
Approach       : DFS
Time           : O(V + E)
Space          : O(V + E)

*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void DFS(Node* node, Node* clone){
        for(Node* n : node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* clone_new = new Node(n->val);
                mp[n] = clone_new;
                clone->neighbors.push_back(clone_new);

                DFS(n, clone_new);
            }else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        mp.clear();
        Node* clone = new Node(node->val);
        mp[node] = clone;
        DFS(node, clone);
        return clone;
    }
};
