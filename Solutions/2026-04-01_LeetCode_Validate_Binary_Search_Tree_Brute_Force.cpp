/*

Problem Name   : Validate Binary Search Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/validate-binary-search-tree/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-01
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        if (!checkLeft(root->left, root->val) ||
            !checkRight(root->right, root->val)) {
            return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool checkLeft(TreeNode* node, int val) {
        if (!node)
            return true;
        if (node->val >= val)
            return false;

        return checkLeft(node->left, val) && checkLeft(node->right, val);
    }

    bool checkRight(TreeNode* node, int val) {
        if (!node)
            return true;
        if (node->val <= val)
            return false;

        return checkRight(node->left, val) && checkRight(node->right, val);
    }
};

// TC = O(N^2)
// SC = O(1)
