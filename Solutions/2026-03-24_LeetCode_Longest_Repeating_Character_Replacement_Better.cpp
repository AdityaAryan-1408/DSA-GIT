/*

Problem Name   : Longest Repeating Character Replacement
Platform       : LeetCode
Topic          : Hash Table, String, Sliding Window
Problem Link   : https://leetcode.com/problems/longest-repeating-character-replacement/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-24
Approach       : Better
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
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                maxf = 0;
                l++;
                for (int i = 0; i < 26; i++) {
                    maxf = max(maxf, hash[i]);
                }
            }
            if ((r - l + 1) - maxf <= k) {
                maxLenghth = max(maxLenghth, r - l + 1);
            }
            r++;
        }
        return maxLenghth;
    }
};

// TC = O(2N * 26) Outer while is N and inner while is N and 26 times the for.
// SC = O(26)
