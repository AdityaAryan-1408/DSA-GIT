/*

Problem Name   : Climbing Stairs
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Memoization
Problem Link   : https://leetcode.com/problems/climbing-stairs/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Brute Force 2
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int  helper(int n) {
        if (n < 0)
            return 0;
        if (n == 0) {
            return 1 ;
        }

        int one = helper(n - 1);
        int two = helper(n - 2);
        return one + two;
    }
    int climbStairs(int n) {
        int cnt = 0;
        return helper(n);
        
    }
};
