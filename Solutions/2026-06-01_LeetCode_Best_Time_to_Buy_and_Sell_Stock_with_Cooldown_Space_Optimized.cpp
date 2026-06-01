/*

Problem Name   : Best Time to Buy and Sell Stock with Cooldown
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2019004450/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Space Optimized
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front1(2, 0), front2(2, 0), curr(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            int profit = 0;
            int buy = -prices[i] + front1[0];
            int notBuy = front1[1];
            curr[1] = max(buy, notBuy);

            int sell = prices[i] + front2[1];
            int notSell = front1[0];
            curr[0] = max(sell, notSell);

            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};
