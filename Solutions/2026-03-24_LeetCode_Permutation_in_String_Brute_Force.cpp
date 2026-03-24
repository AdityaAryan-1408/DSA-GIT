/*

Problem Name   : Permutation in String
Platform       : LeetCode
Topic          : Hash Table, Two Pointers, String, Sliding Window
Problem Link   : https://leetcode.com/problems/permutation-in-string/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-24
Approach       : Brute Force
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool compareHash(vector<int> hash, string& s) {
        for (char c : s) {
            hash[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);
        for (char c : s1)
            hash[c - 'a']++;

        int n = s1.size();
        int i = 0, j = n - 1;
        while (j < s2.size()) {
            string temp = s2.substr(i, n);
            if (compareHash(hash, temp))
                return true;
            i++;
            j++;
        }
        return false;
    }
};

// TC = O(M * N)
// SC = O(1)
