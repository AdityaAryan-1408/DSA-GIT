/*

Problem Name   : Climbing Stairs
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Memoization
Problem Link   : https://leetcode.com/problems/climbing-stairs/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : SpaceOptimization
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1)
            return 1;
        int prev2 = 1, prev1 = 1;
        int curr;
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
