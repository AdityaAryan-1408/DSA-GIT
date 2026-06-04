/*

Problem Name   : Maximum Product Subarray
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-product-subarray/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Brute Force
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            res = max(res, cur);
            for (int j = i + 1; j < nums.size(); j++) {
                cur *= nums[j];
                res = max(res, cur);
            }
        }
        return res;
    }
};
