/*

Problem Name   : Balanced Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/balanced-binary-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    vector<int>dfs(Node * root){
        if(!root) return {1, 0};

        vector<int>left = dfs(root->left);
        vector<int>right = dfs(root->right);

        bool balanced = (left[0] == 1 && right[0] == 1) &&
        abs(left[1] - right[1]) <= 1;

        int height = 1 + max(left[1], right[1]);

        return {balanced ? 1 : 0, height};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
};

// TC = O(N)
// SC = O(N)
