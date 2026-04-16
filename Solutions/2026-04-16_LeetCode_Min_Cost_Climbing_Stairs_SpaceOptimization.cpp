/*

Problem Name   : Min Cost Climbing Stairs
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1980303099/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : SpaceOptimization
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        int a = cost[0];
        int b = cost[1];
        if (n == 2)
            return min(a, b);

        for (int i = 2; i < n; i++) {
            cost[i] = cost[i] + min(a, b);
            a = b;
            b = cost[i];
        }

        return 0 + min(a, b);
    }
};
