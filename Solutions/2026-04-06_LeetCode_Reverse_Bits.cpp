/*

Problem Name   : Reverse Bits
Platform       : LeetCode
Topic          : Divide and Conquer, Bit Manipulation
Problem Link   : https://leetcode.com/problems/reverse-bits/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-06
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    int reverseBits(int n) {
        if (n == 0)
            return 0;

        int res = 0;
        for (int i = 1; i <= 32; i++) {
            res <<= 1;
            res = res | (n & 1);
            n >>= 1;
        }
        return res;
    }
};
