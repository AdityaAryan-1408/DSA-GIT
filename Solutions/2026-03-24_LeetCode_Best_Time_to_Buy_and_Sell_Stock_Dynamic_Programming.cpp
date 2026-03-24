/*

Problem Name   : Best Time to Buy and Sell Stock
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Sliding Window
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-24
Approach       : Dynamic Programming
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};
