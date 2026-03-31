/*

Problem Name   : Binary Tree Level Order Traversal
Platform       : LeetCode
Topic          : Tree, Breadth-First Search, Binary Tree
Problem Link   : https://leetcode.com/problems/binary-tree-level-order-traversal/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-31
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>levelOrder;
        if(!root) return levelOrder;

        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i = 0; i< size; i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                level.push_back(curr->val);
            }
            levelOrder.push_back(level);
        }
        return levelOrder;
    }
};
