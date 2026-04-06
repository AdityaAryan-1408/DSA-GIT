/*

Problem Name   : Sum of Two Integers
Platform       : LeetCode
Topic          : Math, Bit Manipulation
Problem Link   : https://leetcode.com/problems/sum-of-two-integers/submissions/1510277949/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
