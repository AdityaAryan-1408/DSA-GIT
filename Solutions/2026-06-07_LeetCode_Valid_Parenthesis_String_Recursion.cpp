/*

Problem Name   : Valid Parenthesis String
Platform       : LeetCode
Topic          : String, Dynamic Programming, Stack, Greedy
Problem Link   : https://leetcode.com/problems/valid-parenthesis-string/submissions/2025496719/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-07
Approach       : Recursion
Time           : O(N ^ 2)
Space          : O(N ^ 2)

*/

class Solution {
public:
    int n;
    bool helper(int i, int open, string& s) {
        if (i == n) {
            return open == 0;
        }

        bool isValid = false;
        if (s[i] == '*') {
            isValid |= helper(i + 1, open + 1, s);
            isValid |= helper(i + 1, open, s);
            if (open > 0)
                isValid |= helper(i + 1, open - 1, s);
        } else if (s[i] == '(') {
            isValid |= helper(i + 1, open + 1, s);
        } else if (open > 0) {
            isValid |= helper(i + 1, open - 1, s);
        }
        return isValid;
    }
    bool checkValidString(string s) {
        n = s.size();
        return helper(0, 0, s);
    }
};
