/*

Problem Name   : Valid Anagram
Platform       : LeetCode
Topic          : Hash Table, String, Sorting
Problem Link   : https://leetcode.com/problems/valid-anagram/submissions/1950510642/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-16
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> hash(26, 0);
        for (char c : s)
            hash[c - 'a']++;
        for (char c : t)
            hash[c - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (hash[i] < 0)
                return false;
        }
        return true;
    }
};
