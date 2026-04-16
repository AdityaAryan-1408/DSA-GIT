/*

Problem Name   : Climbing Stairs
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Memoization
Problem Link   : https://leetcode.com/problems/climbing-stairs/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Math
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        n++;
        return round((pow(phi, n) - pow(psi, n)) / sqrt5);
    }
};
