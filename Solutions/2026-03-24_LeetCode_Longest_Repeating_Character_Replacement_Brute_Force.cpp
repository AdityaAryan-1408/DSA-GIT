/*

Problem Name   : Longest Repeating Character Replacement
Platform       : LeetCode
Topic          : Hash Table, String, Sliding Window
Problem Link   : https://leetcode.com/problems/longest-repeating-character-replacement/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-24
Approach       : Brute Force
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++) {
            int hash[26] = {0}, maxf = 0;
            for (int j = i; j < s.size(); j++) {
                hash[s[j] - 'A']++;
                maxf = max(maxf, hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxf;
                if (changes <= k) {
                    maxLength = max(maxLength, j - i + 1);
                } else
                    break;
            }
        }
        return maxLength;
    }
};

// Max number of conversion required are given by: Length - Max frequency Character
// TC = O(N^2)
// SC = O(26)
