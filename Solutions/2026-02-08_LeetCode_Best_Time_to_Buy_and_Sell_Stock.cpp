/*

Problem Name   : Best Time to Buy and Sell Stock
Platform       : LeetCode
Topic          : Top Interview 150, Two Pointer
Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Approach with O(n) time and O(n) space due to the greatestRight vector
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> greatestRight(n, 0);
        greatestRight[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            greatestRight[i] = max(greatestRight[i + 1], prices[i]);
        }

        int maxProfit = -1;
        for (int i = 0; i < n; i++) {
            int profit = abs(greatestRight[i] - prices[i]);
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
    // 2 loop approach with O(n^2) time and O(1) space, TLE
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(profit, maxProfit);
            }
        }
        return maxProfit;
    }
    // Approach with O(n) time and O(1) space
    // by keeping track of the minimum price seen so far and calculating the profit at each step
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
int main() {
    Solution s;

    return 0;
}