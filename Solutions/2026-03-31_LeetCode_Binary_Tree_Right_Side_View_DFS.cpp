/*

Problem Name   : Binary Tree Right Side View
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-right-side-view/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-31
Approach       : DFS

*/

using Node = TreeNode;
class Solution {
public:
    void preOrder(Node* root, int level, vector<int>& res) {
        if (!root)
            return;

        if (res.size() < level) {
            res.push_back(root->val);
        }

        preOrder(root->right, level + 1, res);
        preOrder(root->left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preOrder(root, 1, res);
        return res;
    }
};
