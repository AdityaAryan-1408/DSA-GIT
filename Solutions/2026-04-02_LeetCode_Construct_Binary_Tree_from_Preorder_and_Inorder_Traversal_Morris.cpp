/*

Problem Name   : Construct Binary Tree from Preorder and Inorder Traversal
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-02
Approach       : Morris
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        Node* head = new Node(0);
        Node* curr = head;

        int i = 0, j = 0, n = preorder.size();

        while (i < n && j < n) {
            curr->right = new Node(preorder[i], nullptr, curr->right);
            curr = curr->right;
            i++;
            while (i < n && curr->val != inorder[j]) {
                curr->left = new Node(preorder[i], nullptr, curr);
                curr = curr->left;
                i++;
            }
            j++;
            while (curr->right && j < n && curr->right->val == inorder[j]) {
                Node* prev = curr->right;
                curr->right = nullptr;
                curr = prev;
                j++;
            }
        }
        return head->right;
    }
};

// TC = O(N)
// SC = O(1)
