/*

Problem Name   : Pow(x, n)
Platform       : LeetCode
Topic          : Math, Recursion
Problem Link   : https://leetcode.com/problems/powx-n/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-20
Approach       : Alternative 2

*/

// Only works for n >= 0

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        return x * myPow(x, n - 1);
    }
};
