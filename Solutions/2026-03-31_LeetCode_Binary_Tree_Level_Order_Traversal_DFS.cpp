/*

Problem Name   : Binary Tree Level Order Traversal
Platform       : LeetCode
Topic          : Tree, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-level-order-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-31
Approach       : DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    vector<vector<int>>res;
    void DFS(Node* root, int depth){
        if(!root) return;

        if(res.size() == depth){
            res.push_back(vector<int>());
        }

        res[depth].push_back(root->val);
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root, 0);
        return res;
    }
};
