/*

Problem Name   : Construct Binary Tree from Preorder and Inorder Traversal
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-02
Approach       : Map
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    TreeNode* buildTreePreIn(vector<int>& preorder, int preStart, int preEnd,
                             vector<int>& inorder, int inStart, int inEnd,
                             unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreePreIn(preorder, preStart + 1, preStart + numsLeft,
                                    inorder, inStart, inRoot - 1, mp);
        root->right = buildTreePreIn(preorder, preStart + 1 + numsLeft, preEnd,
                                     inorder, inRoot + 1, inEnd, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = buildTreePreIn(preorder, 0, preorder.size() - 1,
                                        inorder, 0, inorder.size() - 1, mp);

        return root;
    }
};

// TC = O(N)
// SC = O(N)
