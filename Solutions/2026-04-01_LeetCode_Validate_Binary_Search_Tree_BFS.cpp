/*

Problem Name   : Validate Binary Search Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Binary Search Tree, Binary Tree
Problem Link   : https://leetcode.com/problems/validate-binary-search-tree/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-01
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

*/
using Node = TreeNode;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        queue<tuple<Node*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));
        while (!q.empty()) {
            auto [node, minVal, maxVal] = q.front();
            q.pop();

            if (node->val <= minVal || node->val >= maxVal) {
                return false;
            }
            if (node->left)
                q.push(make_tuple(node->left, minVal, node->val));
            if (node->right)
                q.push(make_tuple(node->right, node->val, maxVal));
        }
        return true;
    }
};

// TC = O(N)
// SC = O(N)
