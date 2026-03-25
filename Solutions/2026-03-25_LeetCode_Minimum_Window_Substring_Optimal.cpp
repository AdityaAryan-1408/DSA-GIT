/*

Problem Name   : Minimum Window Substring
Platform       : LeetCode
Topic          : Hash Table, String, Sliding Window
Problem Link   : https://leetcode.com/problems/minimum-window-substring/submissions/1958788688/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-25
Approach       : Optimal
Time           : O(N)
Space          : O(K) ~ O(1)

*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n)
            return "";

        unordered_map<char, int> hash;
        for (char c : t) {
            hash[c]++;
        }

        int requiredCount = t.size();
        int i = 0, j = 0;

        int windowSize = INT_MAX;
        int start = 0;

        while (j < n) {
            char curr = s[j];
            if (hash[curr] > 0) {
                requiredCount--;
            }
            hash[curr]--;
            while (requiredCount == 0) {
                int currWindowSize = j - i + 1;
                if (currWindowSize < windowSize) {
                    windowSize = currWindowSize;
                    start = i;
                }

                hash[s[i]]++;
                if (hash[s[i]] > 0) {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return min(windowSize, n + 1) == n + 1 ? ""
                                               : s.substr(start, windowSize);
    }
};
