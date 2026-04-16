/*

Problem Name   : Climbing Stairs
Platform       : LeetCode
Topic          : Math, Dynamic Programming, Memoization
Problem Link   : https://leetcode.com/problems/climbing-stairs/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-16
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    void helper(int n, int& cnt){
        if(n < 0) return;
        if(n == 0){
            cnt++;
            return;
        }

        helper(n - 1, cnt);
        helper(n - 2, cnt);
    }
    int climbStairs(int n)  {
        int cnt = 0;
        helper(n, cnt);
        return cnt;
    }
};
