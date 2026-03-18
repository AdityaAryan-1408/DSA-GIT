/*

Problem Name   : Valid Palindrome
Platform       : LeetCode
Topic          : Two Pointers, String
Problem Link   : https://leetcode.com/problems/valid-palindrome/submissions/1952382516/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-18
Approach       : Alternative
Time           : O(N)
Space          : O(1)

*/

class Solution {
   public:
    bool isValid(char x) {
        if (x >= 'a' && x <= 'z') return true;
        if (x >= 'A' && x <= 'Z') return true;
        if (x >= '0' && x <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.size();
        cout << s << endl;
        int i = 0, j = n - 1;
        while (i < j) {
            if (!isValid(s[i])) {
                i++;
                continue;
            } else if (!isValid(s[j])) {
                j--;
                continue;
            } else {
                if (s[i] != s[j]) return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// TC = O(2N)
// SC = O(1)
