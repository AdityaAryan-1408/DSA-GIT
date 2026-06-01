/*

Problem Name   : Best Time to Buy and Sell Stock with Cooldown
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2019004450/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Memoization
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int helper(int i, bool canBuy, vector<int>& prices, vector<vector<int>>&dp) {
        if (i >= n) {
            return 0;
        }
        int profit;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, false, prices, dp);
            int notBuy = helper(i + 1, true, prices, dp);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[i] + helper(i + 2, true, prices, dp);
            int notSell = helper(i + 1, false, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, true, prices, dp);
    }
};
