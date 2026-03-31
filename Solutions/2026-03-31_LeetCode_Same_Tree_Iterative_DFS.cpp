/*

Problem Name   : Same Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/same-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-31
Approach       : Iterative DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<Node*, Node*>> st;
        st.push({p, q});
        while (!st.empty()) {
            auto [node1, node2] = st.top();
            st.pop();

            if (!node1 && !node2)
                continue;
            if (!node1 || !node2 || node1->val != node2->val)
                return false;

            st.push({node1->left, node2->left});
            st.push({node1->right, node2->right});
        }
        return true;
    }
};
