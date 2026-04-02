/*

Problem Name   : Construct Binary Tree from Preorder and Inorder Traversal
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-02
Approach       : DFS Optimal
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    int preInd = 0;
    int inInd = 0;
    Node* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (preInd >= preorder.size())
            return nullptr;
        if (inorder[inInd] == limit) {
            inInd++;
            return nullptr;
        }

        Node* root = new Node(preorder[preInd++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};

// TC = O(N)
// SC = O(N)
