/*

Problem Name   : Maximum Product of Splitted Binary Tree
Platform       : LeetCode
Topic          : Binary Tree
Problem Link   : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/?envType=daily-question&envId=2026-01-07
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-07

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    const int mod = 1e9 + 7;
    long long ans = INT_MIN, total = 0;
    int dfs(TreeNode* root, bool compute_ans = 0) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left, compute_ans) +
                  dfs(root->right, compute_ans);
        if (compute_ans) ans = max(ans, (total - sum) * sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        dfs(root, 1);
        return ans % mod;
    }
};

int main() {
    Solution s;

    return 0;
}