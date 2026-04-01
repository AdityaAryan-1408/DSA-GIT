/*

Problem Name   : Kth Smallest Element in a BST
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-01
Approach       : Inorder
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& arr) {
        if (!node) {
            return;
        }
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        int kLargest = arr[arr.size() - k];
        int kSmallest = arr[k - 1];
        return kSmallest;
    }
};

// TC = O(N)
// SC = O(N)
