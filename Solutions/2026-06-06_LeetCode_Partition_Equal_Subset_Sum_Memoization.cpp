/*

Problem Name   : Partition Equal Subset Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/partition-equal-subset-sum/submissions/2023995080/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-06
Approach       : Memoization

*/

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool helper(int i, int target, vector<int>& nums) {
        if (target == 0) {
            return true;
        }
        if (i == n - 1) {
            return nums[n - 1] == target;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        bool notTake = helper(i + 1, target, nums);
        bool take = false;
        if (target >= nums[i]) {
            take = helper(i + 1, target - nums[i], nums);
        }
        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1)
            return false;
        int target = total / 2;
        dp.assign(n, vector<int>(target + 1, -1));
        return helper(0, target, nums);
    }
};
