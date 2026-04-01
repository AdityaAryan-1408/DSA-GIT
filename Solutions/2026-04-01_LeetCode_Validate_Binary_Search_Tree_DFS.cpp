/*

Problem Name   : Validate Binary Search Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/validate-binary-search-tree/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-01
Approach       : DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    bool isValid(Node* node, long low, long high) {
        if (!node)
            return true;

        if (node->val >= high || node->val <= low)
            return false;

        return isValid(node->left, low, node->val) &&
               isValid(node->right, node->val, high);
    }
    bool isValidBST(TreeNode* root) { return isValid(root, LONG_MIN, LONG_MAX); }
};

// TC = O(N)
// SC = O(N)
