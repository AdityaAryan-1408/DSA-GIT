/*

Problem Name   : Pow(x, n)
Platform       : LeetCode
Topic          : Math, Recursion
Problem Link   : https://leetcode.com/problems/powx-n/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-20
Approach       : Brute Force

*/

class Solution {
public:
    double myPow(double x, int n) {
        int check = n;
        if (check < 0)
            check *= -1;

        double res = 1.0;
        for (int i = 0; i < check; i++) {
            res *= x;
        }

        return (n < 0 ? 1 / res : res);
    }
};

// Gives TLE
// TC = O(N)
// SC = O(1)
