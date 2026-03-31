/*

Problem Name   : Lowest Common Ancestor of a Binary Search Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1965009915/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-31
Time           : O(log N)
Space          : O(1)

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        int curr = root->val;
        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
