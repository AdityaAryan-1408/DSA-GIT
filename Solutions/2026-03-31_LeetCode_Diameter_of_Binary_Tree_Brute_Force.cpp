/*

Problem Name   : Diameter of Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/diameter-of-binary-tree/submissions/1964687417/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : Brute Force
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);

        int diameter = leftHeight + rightHeight;
        int sub = max(diameterOfBinaryTree(root->left),
                      diameterOfBinaryTree(root->right));
        return max(diameter, sub);
    }
};

// TC = O(N^2)
// SC = O(N)
