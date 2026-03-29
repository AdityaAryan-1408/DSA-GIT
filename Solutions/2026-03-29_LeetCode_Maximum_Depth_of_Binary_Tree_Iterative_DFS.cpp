/*

Problem Name   : Maximum Depth of Binary Tree
Platform       : LeetCode
Topic          : Tree, Depth-First Search, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1963204569/
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        stack<pair<Node*, int>> st;
        st.push({root, 1});
        int maxDepth = 0;
        while (!st.empty()) {
            auto current = st.top();
            st.pop();
            Node* node = current.first;
            int depth = current.second;
            if (node) {
                maxDepth = max(maxDepth, depth);
                st.push({node->left, depth + 1});
                st.push({node->right, depth + 1});
            }
        }
        return maxDepth;
    }
};
