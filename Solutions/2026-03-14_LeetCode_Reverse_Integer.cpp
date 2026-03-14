/*

Problem Name   : Reverse Integer
Platform       : LeetCode
Topic          : Math
Problem Link   : https://leetcode.com/problems/reverse-integer/submissions/1948376422/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-14
Time           : O(log |x|)
Space          : O(1)

*/

class Solution {
public:
    int reverse(int x) {
        int y = x;
        long long rev = 0;
        while(y!= 0)
        {
            long long rem = y%10;
            rev = rev*10 + rem;
            y /= 10;
        }
        if(rev > INT_MAX || rev < INT_MIN)
            return 0;
        
        return rev;
    }
};
