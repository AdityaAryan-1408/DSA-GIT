/*

Problem Name   : Product of Array Except Self
Platform       : LeetCode
Topic          : Array, Prefix Sum, Math
Problem Link   : https://leetcode.com/problems/product-of-array-except-self/submissions/1951530043/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Better
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = count(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(n == zeroCnt){
            vector<int>res(n, 0);
            return res;
        }
        vector<int> res(n);
        int product = 1;
        if (zeroCnt == 0) {
            for (int x : nums)
                product *= x;

            for (int i = 0; i < n; i++) {
                res[i] = product / nums[i];
            }
        } else {
            for (int x : nums) {
                if (x != 0)
                    product *= x;
            }

            if(zeroCnt > 1) product = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0)
                    res[i] = product;
                else
                    res[i] = 0;
            }
        }
        return res;
    }
};

// Uses the division operator despite being explicitly mentioned not to use.
// TC = O(N)
// SC = O(1)
