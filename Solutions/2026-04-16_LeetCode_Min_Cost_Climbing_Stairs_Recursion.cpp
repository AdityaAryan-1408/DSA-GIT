/*

Problem Name   : Min Cost Climbing Stairs
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1980303099/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Recursion
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int helper(vector<int>& cost, int i) {
        if (i >= n)
            return 0;

        int a = cost[i] + helper(cost, i + 1);
        int b = cost[i] + helper(cost, i + 2);

        return min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        return min(helper(cost, 0), helper(cost, 1));
    }
};
