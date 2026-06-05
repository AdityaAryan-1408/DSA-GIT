/*

Problem Name   : Longest Increasing Subsequence
Platform       : LeetCode
Topic          : Array, Binary Search, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-increasing-subsequence/submissions/2022964327/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-05
Approach       : Space Optimization
Time           : O(N * P)
Space          : O(N * P)

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int LIS = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
                LIS = max(LIS, dp[i]);
            }
        }
        return LIS;
    }
};
