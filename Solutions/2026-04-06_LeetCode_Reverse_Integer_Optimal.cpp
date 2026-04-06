/*

Problem Name   : Reverse Integer
Platform       : LeetCode
Topic          : Math
Problem Link   : https://leetcode.com/problems/reverse-integer/submissions/1970814298/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06
Approach       : Optimal
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    int reverse(int x) {
        const int MIN = -2147483648; // -2^31
        const int MAX = 2147483647;  // 2^31 - 1

        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
                return 0;
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
                return 0;
            res = (res * 10) + digit;
        }

        return res;
    }
};
