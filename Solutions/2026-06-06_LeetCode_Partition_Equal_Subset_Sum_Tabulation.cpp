/*

Problem Name   : Partition Equal Subset Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/partition-equal-subset-sum/submissions/2023995080/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-06
Approach       : Tabulation

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1)
            return false;
        int target = total / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (j >= nums[i]) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};
