/*

Problem Name   : Count Good Nodes in Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-31
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<Node*, int>> q;
        q.push({root, INT_MIN});

        while (!q.empty()) {
            auto [node, maxVal] = q.front();
            q.pop();
            if (node->val >= maxVal) {
                res++;
            }
            if (node->left)
                q.push({node->left, max(maxVal, node->val)});
            if (node->right)
                q.push({node->right, max(maxVal, node->val)});
        }
        return res;
    }
};
