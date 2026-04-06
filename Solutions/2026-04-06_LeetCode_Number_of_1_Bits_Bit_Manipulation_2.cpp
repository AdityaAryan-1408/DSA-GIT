/*

Problem Name   : Number of 1 Bits
Platform       : LeetCode
Topic          : Divide and Conquer, Bit Manipulation
Problem Link   : https://leetcode.com/problems/number-of-1-bits/submissions/1970694016/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-06
Approach       : Bit Manipulation 2
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n) {
            n = n & n - 1;
            cnt++;
        }
        return cnt;
    }
};

// TC = O(no. of Set bits)
// SC = O(1)
