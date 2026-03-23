/*

Problem Name   : Longest Substring Without Repeating Characters
Platform       : LeetCode
Topic          : Hash Table, String, Sliding Window
Problem Link   : https://leetcode.com/problems/longest-substring-without-repeating-characters/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-23
Approach       : Optimal 2
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxLen = 0;
        while (j < n) {
            if (mp[s[j]] >= 1) {
                mp[s[i]]--;
                maxLen = max(maxLen, j - i);
                i++;
            } else {
                mp[s[j]]++;
                j++;
            }
        }
        maxLen = max(maxLen, j - i);
        return maxLen;
    }
};
