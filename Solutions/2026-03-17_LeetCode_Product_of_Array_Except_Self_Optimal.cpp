/*

Problem Name   : Product of Array Except Self
Platform       : LeetCode
Topic          : Array, Prefix Sum, Math
Problem Link   : https://leetcode.com/problems/product-of-array-except-self/submissions/1951530043/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = prefix[i] * suffix[i];

        return res;
    }
};

// TC = O(N)
// SC = O(N) for prefix and Suffix arrays
