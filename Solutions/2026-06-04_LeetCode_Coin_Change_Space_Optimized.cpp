/*

Problem Name   : Coin Change
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Breadth-First Search
Problem Link   : https://leetcode.com/problems/coin-change/submissions/2022108571/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Space Optimized
Time           : O(N * T)
Space          : O(N * T)

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1), curr(amount + 1);
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
            else
                prev[target] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = prev[target];
                int take = INT_MAX;
                if (coins[i] <= target) {
                    take = 1 + curr[target - coins[i]];
                }
                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        int res = prev[amount];
        return (res == 1e9 || res == INT_MAX) ? -1 : res;
    }
};
