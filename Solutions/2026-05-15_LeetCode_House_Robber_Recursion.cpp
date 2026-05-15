/*

Problem Name   : House Robber
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/house-robber/submissions/2003720947/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15
Approach       : Recursion
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int n;
    int helper(vector<int>& nums, int i) {
        if (i == n - 1)
            return nums[i];

        if (i >= n)
            return 0;

        int pick = nums[i] + helper(nums, i + 2);
        int notPick = helper(nums, i + 1);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        return helper(nums, 0);
    }
};
