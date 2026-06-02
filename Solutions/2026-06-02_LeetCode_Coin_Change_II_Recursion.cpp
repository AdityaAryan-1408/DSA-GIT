/*

Problem Name   : Coin Change II
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/coin-change-ii/submissions/2019965838/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Recursion
Time           : O(N * Amount)
Space          : O(N * Amount)

*/

class Solution {
public:
    int n;
    int helper(int i, int target, vector<int>& coins) {
        if (i == n - 1) {
            if (target % coins[n - 1] == 0)
                return 1;
            return 0;
        }

        int take = 0, notTake = 0;
        notTake = helper(i + 1, target, coins);
        if (coins[i] <= target) {
            take = helper(i, target - coins[i], coins);
        }
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        return helper(0, amount, coins);
    }
};
