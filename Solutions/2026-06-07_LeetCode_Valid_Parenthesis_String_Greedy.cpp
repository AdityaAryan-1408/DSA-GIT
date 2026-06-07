/*

Problem Name   : Valid Parenthesis String
Platform       : LeetCode
Topic          : String, Dynamic Programming, Stack, Greedy
Problem Link   : https://leetcode.com/problems/valid-parenthesis-string/submissions/2025496719/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-07
Approach       : Greedy
Time           : O(N ^ 2)
Space          : O(N ^ 2)

*/

class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }

            if (open < 0) {
                return false;
            }
        }

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }

            if (close < 0) {
                return false;
            }
        }

        return true;
    }
};
