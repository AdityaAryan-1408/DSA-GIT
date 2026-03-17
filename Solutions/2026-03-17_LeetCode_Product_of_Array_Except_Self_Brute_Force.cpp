/*

Problem Name   : Product of Array Except Self
Platform       : LeetCode
Topic          : Array, Prefix Sum, Math
Problem Link   : https://leetcode.com/problems/product-of-array-except-self/submissions/1951530043/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Brute Force
Time           : O(N)
Space          : O(1)

*/

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int temp = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    temp *= nums[j];
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

// TC = O(N^2)
// SC = O(1) Output array is not considered.
