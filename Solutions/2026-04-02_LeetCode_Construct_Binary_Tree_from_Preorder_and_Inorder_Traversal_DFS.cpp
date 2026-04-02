/*

Problem Name   : Construct Binary Tree from Preorder and Inorder Traversal
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-02
Approach       : DFS
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        Node* root = new Node(preorder[0]);
        auto mid =
            find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};

// TC = O(N^2)
// SC = O(N)
