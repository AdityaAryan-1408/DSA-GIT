/*

Problem Name   : Target Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/target-sum/submissions/2020063647/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Tabulation
Time           : O(N * S)
Space          : O(N * S)

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (auto &p : dp[i]) {
                dp[i + 1][p.first + nums[i]] += p.second;
                dp[i + 1][p.first - nums[i]] += p.second;
            }
        }
        return dp[n][target];
    }
};
