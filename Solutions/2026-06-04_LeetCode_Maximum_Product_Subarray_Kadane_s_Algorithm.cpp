/*

Problem Name   : Maximum Product Subarray
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-product-subarray/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Kadane's Algorithm
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
