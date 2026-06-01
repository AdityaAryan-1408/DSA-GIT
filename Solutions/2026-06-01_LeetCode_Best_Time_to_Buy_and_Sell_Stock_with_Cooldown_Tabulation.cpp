/*

Problem Name   : Best Time to Buy and Sell Stock with Cooldown
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2019004450/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Tabulation
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;
                if (canBuy) {
                    int buy = -prices[i] + dp[i + 1][0];
                    int notBuy = dp[i + 1][1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = prices[i] + dp[i + 2][1];
                    int notSell = dp[i + 1][0];
                    profit = max(sell, notSell);
                }
                dp[i][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};
