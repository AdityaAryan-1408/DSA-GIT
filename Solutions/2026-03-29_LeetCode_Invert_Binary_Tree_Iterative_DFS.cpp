/*

Problem Name   : Invert Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/invert-binary-tree/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-29
Approach       : Iterative DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            swap(node->right, node->left);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return root;
    }
};
