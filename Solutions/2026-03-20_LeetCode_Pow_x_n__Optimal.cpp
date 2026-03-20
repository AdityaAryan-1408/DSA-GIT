/*

Problem Name   : Pow(x, n)
Platform       : LeetCode
Topic          : Math, Recursion
Problem Link   : https://leetcode.com/problems/powx-n/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-20
Approach       : Optimal

*/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        double res = helper(x, abs(static_cast<long>(n)));
        return (n >= 0) ? res : 1 / res;
    }

private:
    double helper(double x, long n) {
        if (n == 0) {
            return 1;
        }
        double half = helper(x, n / 2);
        return (n % 2 == 0) ? half * half : x * half * half;
    }
};

// Binary Exponentiation Recursive
// TC = O(Log N)
// SC = O(Log N)
