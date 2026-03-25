/*

Problem Name   : Minimum Window Substring
Platform       : LeetCode
Topic          : Hash Table, String, Sliding Window
Problem Link   : https://leetcode.com/problems/minimum-window-substring/submissions/1958788688/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-25
Approach       : Two Pointer 1
Time           : O(N)
Space          : O(K) ~ O(1)

*/

class Solution {
public:
    bool compareHash(unordered_map<char, int>& hash,
                     unordered_map<char, int>& check) {
        for (auto& it : hash) {
            char c = it.first;
            int required = it.second;

            if (check[c] < required) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> hash;
        for (char x : t)
            hash[x]++;

        int n = s.size();
        int i = 0, j = 0;
        int startIndex = 0;
        unordered_map<char, int> check;
        int minLen = INT_MAX;
        while (j < n) {
            check[s[j]]++;
            j++;
            while (i < j && compareHash(hash, check)) {
                if (j - i < minLen) {
                    minLen = j - i;
                    startIndex = i;
                }
                check[s[i]]--;
                i++;
            }
        }
        if (minLen == INT_MAX) return "";
        string res = s.substr(startIndex, minLen);
        return res;
    }
};

// TC = O(n · k) (≈ O(n) for fixed alphabet)
// SC = O(k)
