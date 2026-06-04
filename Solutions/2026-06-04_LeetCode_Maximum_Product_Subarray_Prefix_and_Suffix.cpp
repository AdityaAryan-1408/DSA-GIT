/*

Problem Name   : Maximum Product Subarray
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-product-subarray/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Prefix and Suffix
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        int prefix = 0, suffix = 0;

        for (int i = 0; i < n; i++) {
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            suffix = nums[n - 1 - i] * (suffix == 0 ? 1 : suffix);
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};
