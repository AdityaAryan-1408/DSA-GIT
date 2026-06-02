/*

Problem Name   : Coin Change II
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/coin-change-ii/submissions/2019965838/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Space Optimized
Time           : O(N * Amount)
Space          : O(N * Amount)

*/

using ull = unsigned long long;
class Solution {
public:
    ull change(int target, vector<int>& coins) {
        int n = coins.size();
        vector<ull> prev(target + 1, 0), curr(target + 1, 0);
        for (int t = 0; t <= target; t++) {
            if (t % coins[0] == 0)
                prev[t] = 1;
            else
                prev[t] = 0;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= target; t++) {
                ull notTake = prev[t];
                ull take = 0;
                if (coins[ind] <= t)
                    take = curr[t - coins[ind]];

                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};
