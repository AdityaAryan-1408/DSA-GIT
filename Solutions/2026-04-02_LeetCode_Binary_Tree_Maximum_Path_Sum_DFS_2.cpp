/*

Problem Name   : Binary Tree Maximum Path Sum
Platform       : LeetCode
Topic          : Dynamic Programming, Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-maximum-path-sum/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-04-02
Approach       : DFS 2
Time           : O(N)
Space          : O(N)

*/

class Solution {
    int res = INT_MIN;

    int getMax(TreeNode* root) {
        if (!root)
            return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + max(left, right);
        return max(0, path);
    }

    void dfs(TreeNode* root) {
        if (!root)
            return;
        int left = getMax(root->left);
        int right = getMax(root->right);
        res = max(res, root->val + left + right);
        dfs(root->left);
        dfs(root->right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// TC = O(N^2)
// SC = O(N)
