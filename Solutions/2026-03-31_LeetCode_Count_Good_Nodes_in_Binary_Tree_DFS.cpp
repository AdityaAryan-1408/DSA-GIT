/*

Problem Name   : Count Good Nodes in Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    int dfs(Node* node, int maxSoFar) {
        if (!node)
            return 0;

        int res = (node->val >= maxSoFar) ? 1 : 0;
        maxSoFar = max(maxSoFar, node->val);
        res += dfs(node->left, maxSoFar);
        res += dfs(node->right, maxSoFar);
        return res;
    }
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
};
