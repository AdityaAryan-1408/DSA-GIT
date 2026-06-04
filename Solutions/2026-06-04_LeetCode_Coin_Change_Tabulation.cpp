/*

Problem Name   : Coin Change
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Breadth-First Search
Problem Link   : https://leetcode.com/problems/coin-change/submissions/2022108571/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Tabulation
Time           : O(N * T)
Space          : O(N * T)

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = dp[i - 1][target];
                int take = INT_MAX;
                if (coins[i] <= target) {
                    take = 1 + dp[i][target - coins[i]];
                }
                dp[i][target] = min(take, notTake);
            }
        }
        int res = dp[n - 1][amount];
        return (res == 1e9 || res == INT_MAX) ? -1 : res;
    }
};
