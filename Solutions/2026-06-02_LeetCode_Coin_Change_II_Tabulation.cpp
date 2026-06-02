/*

Problem Name   : Coin Change II
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/coin-change-ii/submissions/2019965838/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Tabulation
Time           : O(N * Amount)
Space          : O(N * Amount)

*/

using ll = unsigned long long;
class Solution {
public:
    ll change(int target, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ll>> dp(n, vector<ll>(target + 1, 0));
        for (int t = 0; t <= target; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = 1;
            else
                dp[0][t] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                ll notTake = dp[i - 1][t];
                ll take = 0;
                if (coins[i] <= t) {
                    take = dp[i][t - coins[i]];
                }
                dp[i][t] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }
};
