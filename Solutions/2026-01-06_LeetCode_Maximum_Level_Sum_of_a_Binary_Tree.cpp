/*

Problem Name   : Maximum Level Sum of a Binary Tree
Platform       : LeetCode
Topic          : Binary Tree
Problem Link   : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-06

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
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = 0, level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int sumAtCurrentLevel = 0;
            for (int sz = q.size(); sz > 0; --sz) {
                TreeNode* node = q.front();
                q.pop();
                sumAtCurrentLevel += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (maxSum < sumAtCurrentLevel) {
                maxSum = sumAtCurrentLevel;
                ans = level;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}