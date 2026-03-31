/*

Problem Name   : Diameter of Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/diameter-of-binary-tree/submissions/1964687417/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : DFS
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    int dfs(Node* root, int& res) {
        if (!root)
            return 0;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

// TC = O(N)
// SC = O(h)
