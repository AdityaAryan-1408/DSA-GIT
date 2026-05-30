/*

Problem Name   : Palindromic Substrings
Platform       : LeetCode
Topic          : Two Pointers, String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/palindromic-substrings/submissions/2017413117/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-30
Approach       : Alternative
Time           : O(N ^ 2)
Space          : O(N ^ 2)

*/

class Solution {
public:
    int count = 0;
    void check(string& s, int i, int j, int n) {

        while (i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--; 
            j++; 
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        for (int i = 0; i < n; i++) {
            check(s, i, i, n);
            check(s, i, i + 1, n);
        }
        return count;
    }
};
