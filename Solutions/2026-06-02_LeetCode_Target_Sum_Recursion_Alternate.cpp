/*

Problem Name   : Target Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/target-sum/submissions/2020063647/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Recursion Alternate
Time           : O(N * S)
Space          : O(N * S)

*/

class Solution {
public:
    int helper(vector<int>& nums, int target, int i){
        if(i == nums.size()){
            if(target == 0) return 1;
            return 0;
        }
        int plus = helper(nums, target - nums[i], i + 1);
        int minus = helper(nums, target + nums[i], i + 1);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0);
    }
};
