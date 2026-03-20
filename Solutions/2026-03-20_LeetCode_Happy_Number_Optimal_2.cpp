/*

Problem Name   : Happy Number
Platform       : LeetCode
Topic          : Hash Table, Math, Two Pointers
Problem Link   : https://leetcode.com/problems/happy-number/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-20
Approach       : Optimal 2
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    int digSquare(int n) {
        int sq = 0;
        while (n != 0) {
            sq += (n % 10) * (n % 10);
            n /= 10;
        }
        return sq;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = digSquare(slow);
            fast = digSquare(digSquare(fast));
        }while(slow != fast);

        return slow == 1;
    }
};
