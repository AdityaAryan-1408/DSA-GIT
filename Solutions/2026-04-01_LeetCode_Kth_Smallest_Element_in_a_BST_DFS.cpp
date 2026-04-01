/*

Problem Name   : Kth Smallest Element in a BST
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-01
Approach       : DFS
Time           : O(N)
Space          : O(1)

*/

using Node = TreeNode;
class Solution {
public:
    void dfs(Node* node, vector<int>& temp) {
        if (!node)
            return;

        dfs(node->left, temp);
        temp[0]--;
        if (temp[0] == 0) {
            temp[1] = node->val;
            return;
        }
        dfs(node->right, temp);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res(2);
        res[0] = k;
        dfS(root, res);
        return res[1];
    }
};

// TC = O(N)
// SC = O(N)
