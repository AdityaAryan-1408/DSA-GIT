/*

Problem Name   : Coin Change
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Breadth-First Search
Problem Link   : https://leetcode.com/problems/coin-change/submissions/2022108571/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Recursion
Time           : O(N * T)
Space          : O(N * T)

*/

class Solution {
public:
    int n;
    int helper(int i, int target, vector<int>& coins) {
        if (i == n - 1) {
            if (target % coins[i] == 0) {
                return target / coins[i];
            } else
                return 1e9;
        }

        int notTake = helper(i + 1, target, coins);
        int take = INT_MAX;
        if (coins[i] <= target) {
            take = 1 + helper(i, target - coins[i], coins);
        }
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int target) {
        n = coins.size();
        int res =  helper(0, target, coins);
        return (res == 1e9 || res == INT_MAX) ? -1 : res;
    }
};
