/*

Problem Name   : Same Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/same-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<Node*, Node*>> que;
        que.push({p, q});

        while (!que.empty()) {
            auto [node1, node2] = que.front();
            que.pop();

            if (!node1 && !node2)
                continue;
            if (!node1 || !node2 || node1->val != node2->val)
                return false;

            que.push({node1->left, node2->left});
            que.push({node1->right, node2->right});
        }
        return true;
    }
};
