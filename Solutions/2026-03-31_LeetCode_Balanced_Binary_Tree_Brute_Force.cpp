/*

Problem Name   : Balanced Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/balanced-binary-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    int height(Node* root) {
        if (!root)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {

        if (!root)
            return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// TC = O(N^2)
// SC = O(N)
