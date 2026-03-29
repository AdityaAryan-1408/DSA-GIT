/*

Problem Name   : Maximum Depth of Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1963204569/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-29
Approach       : Recursive DFS
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};
