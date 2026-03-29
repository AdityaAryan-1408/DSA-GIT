/*

Problem Name   : Invert Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/invert-binary-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-29
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return root;
    }
};
