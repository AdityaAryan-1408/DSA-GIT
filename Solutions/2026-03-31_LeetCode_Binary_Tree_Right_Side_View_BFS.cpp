/*

Problem Name   : Binary Tree Right Side View
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-right-side-view/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-31
Approach       : BFS

*/

using Node = TreeNode;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        queue<Node*> q;
        vector<int> res;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* node;
            while (n--) {
                node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(node->val);
        }
        return res;
    }
};
