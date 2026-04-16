/*

Problem Name   : Min Cost Climbing Stairs
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1980303099/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Tabulation
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);

        for (int i = 2; i < n; i++) {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        }

        return 0 + min(cost[n - 1], cost[n - 2]);
    }
};
