/*

Problem Name   : Balanced Binary Tree
Platform       : LeetCode
Topic          : Tree
Problem Link   : https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class TreeNode {
   public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};
class Solution {
   public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1) return -1;

        if (left == -1 || right == -1) return -1;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) { return height(root) != -1; }
};

int main() {
    Solution s;

    return 0;
}