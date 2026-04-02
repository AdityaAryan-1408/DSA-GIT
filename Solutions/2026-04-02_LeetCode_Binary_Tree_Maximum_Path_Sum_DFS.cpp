/*

Problem Name   : Binary Tree Maximum Path Sum
Platform       : LeetCode
Topic          : Dynamic Programming, Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-maximum-path-sum/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-04-02
Approach       : DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    int maxSum;
    int solve(Node* root) {
        if (!root)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int foundBelow = left + right + root->val;
        int eitherOne = max(left, right) + root->val;
        int onlyRoot = root->val;

        maxSum = max({maxSum, eitherOne, onlyRoot, foundBelow});
        return max(onlyRoot, eitherOne);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

// TC = O(N)
// SC = O(N)
