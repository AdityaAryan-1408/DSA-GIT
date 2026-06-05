/*

Problem Name   : Longest Increasing Subsequence
Platform       : LeetCode
Topic          : Array, Binary Search, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-increasing-subsequence/submissions/2022964327/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-05
Approach       : Recursion
Time           : O(N * P)
Space          : O(N * P)

*/

class Solution {
public:
    int n;
    int helper(int i, int prev, vector<int>&nums){
        if(i == n){
            return 0;
        }
        int notTake = helper(i + 1, prev, nums);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + helper(i + 1, i, nums);
        }
        return max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        return helper(0, -1, nums);
    }
};
