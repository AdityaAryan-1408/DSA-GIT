/*

Problem Name   : Construct Binary Tree from Preorder and Inorder Traversal
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-02
Approach       : DFS + Map
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    int preInd = 0;
    unordered_map<int, int> indices;
    Node* dfs(vector<int>& preorder, int l, int r) {
        if (l > r)
            return nullptr;

        int rootVal = preorder[preInd++];
        Node* root = new Node(rootVal);
        int mid = indices[rootVal];
        root->left = dfs(preorder, l, mid - 1);
        root->right = dfs(preorder, mid + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }
};

// TC = O(N)
// SC = O(N)
