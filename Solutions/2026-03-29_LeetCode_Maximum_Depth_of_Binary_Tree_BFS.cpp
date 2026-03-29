/*

Problem Name   : Maximum Depth of Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1963204569/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-29
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<Node*> q;
        q.push(root);
        int maxDepth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            maxDepth++;
        }
        return maxDepth;
    }
};
