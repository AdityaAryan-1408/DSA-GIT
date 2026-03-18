/*

Problem Name   : Valid Palindrome
Platform       : LeetCode
Topic          : Two Pointers, String
Problem Link   : https://leetcode.com/problems/valid-palindrome/submissions/1952382516/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-18
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            } else if (!isalnum(s[j])) {
                j--;
                continue;
            } else {
                if(tolower(s[i]) != tolower(s[j])) return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// TC = O(N)
// SC = O(1)
