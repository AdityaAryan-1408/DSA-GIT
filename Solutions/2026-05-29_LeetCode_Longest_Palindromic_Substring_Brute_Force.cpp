/*

Problem Name   : Longest Palindromic Substring
Platform       : LeetCode
Topic          : Two Pointers, String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-palindromic-substring/submissions/2016369420/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-29
Approach       : Brute Force
Time           : O(N^2)
Space          : O(N^2)

*/

class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        int maxLen = 0;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int len = j - i + 1;
                if (isPalindrome(s, i, j)) {
                    maxLen = max(maxLen, len);
                    if(maxLen == len){
                        ind = i;
                    }
                }
            }
        }
        return s.substr(ind, maxLen);
        
    }
};
