/*

Problem Name   : Burst Balloons
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/burst-balloons/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Memoization

*/

class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int maxx = INT_MIN;
        for (int ind = i; ind <= j; ind++) {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] +
                       helper(i, ind - 1, nums) + helper(ind + 1, j, nums);
            maxx = max(maxx, cost);
        }
        return dp[i][j] =  maxx;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        dp.assign(n+1, vector<int>(n+1, -1));
        return helper(1, nums.size() - 2, nums);
    }
};
