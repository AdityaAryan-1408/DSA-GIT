/*

Problem Name   : Longest Repeating Character Replacement
Platform       : LeetCode
Topic          : Hash Table, String, Sliding Window
Problem Link   : https://leetcode.com/problems/longest-repeating-character-replacement/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-24
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLenghth = 0;
        int l = 0, r = 0, maxf = 0;
        int hash[26] = {0};
        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            if ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                maxf = 0;
                l++;
            }
            if ((r - l + 1) - maxf <= k) {
                maxLenghth = max(maxLenghth, r - l + 1);
            }
            r++;
        }
        return maxLenghth;
    }
};

// TC = O(N)
// SC = O(1)
