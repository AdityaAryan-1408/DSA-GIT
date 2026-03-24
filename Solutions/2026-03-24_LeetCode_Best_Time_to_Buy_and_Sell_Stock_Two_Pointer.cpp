/*

Problem Name   : Best Time to Buy and Sell Stock
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Sliding Window
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-24
Approach       : Two Pointer
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
