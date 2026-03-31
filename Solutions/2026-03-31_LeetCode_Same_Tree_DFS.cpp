/*

Problem Name   : Same Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/same-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : DFS
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};

// TC = O(N)
// SC = O(N)
