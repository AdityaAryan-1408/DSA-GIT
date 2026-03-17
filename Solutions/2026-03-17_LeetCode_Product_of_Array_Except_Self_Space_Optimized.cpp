/*

Problem Name   : Product of Array Except Self
Platform       : LeetCode
Topic          : Array, Prefix Sum, Math
Problem Link   : https://leetcode.com/problems/product-of-array-except-self/submissions/1951530043/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Space Optimized
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }
};

// TC = O(N)
// SC = O(1)
