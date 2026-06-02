/*

Problem Name   : Target Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/target-sum/submissions/2020063647/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Recursion
Time           : O(N * S)
Space          : O(N * S)

*/

class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int curr){
        if(i == nums.size()){
            if(curr == target) return 1;
            return 0;
        }
        int plus = helper(nums, target, i + 1, curr + nums[i]);
        int minus = helper(nums, target, i + 1, curr - nums[i]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};
