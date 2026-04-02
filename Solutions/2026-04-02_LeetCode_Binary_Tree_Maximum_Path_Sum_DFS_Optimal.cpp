/*

Problem Name   : Binary Tree Maximum Path Sum
Platform       : LeetCode
Topic          : Dynamic Programming, Tree, Depth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-maximum-path-sum/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-04-02
Approach       : DFS Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }

        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);

        res = max(res, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
};

// TC = O(N)
// SC = O(N)
