/*

Problem Name   : Best Time to Buy and Sell Stock with Cooldown
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2019004450/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int helper(int i, bool canBuy, vector<int>& prices) {
        if (i >= n) {
            return 0;
        }
        int profit;
        if (canBuy) {
            int buy = -prices[i] + helper(i + 1, false, prices);
            int notBuy = helper(i + 1, true, prices);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[i] + helper(i + 2, true, prices);
            int notSell = helper(i + 1, false, prices);
            profit = max(sell, notSell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        return helper(0, true, prices);
    }
};
