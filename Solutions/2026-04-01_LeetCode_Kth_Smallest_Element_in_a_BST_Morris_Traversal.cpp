/*

Problem Name   : Kth Smallest Element in a BST
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-01
Approach       : Morris Traversal
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        Node* curr = root;
        int ans = -1;
        while (curr) {
            if (!curr->left) {
                k--;
                if (k == 0) {
                    ans = curr->val;
                }
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    k--;
                    if (k == 0) {
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

// TC = O(N)
// SC = O(1)
