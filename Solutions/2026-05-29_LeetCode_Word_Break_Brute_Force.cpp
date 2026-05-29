/*

Problem Name   : Word Break
Platform       : LeetCode
Topic          : Array, Hash Table, String, Dynamic Programming, Trie, Memoization
Problem Link   : https://leetcode.com/problems/word-break/submissions/2016392338/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-29
Approach       : Brute Force
Time           : O(N^3)
Space          : O(N)

*/

class Solution {
public:
    int n;
    unordered_set<string> st;

    bool solve(int i, string& s) {
        if (i >= n)
            return true;

        if (st.find(s) != st.end())
            return true;

        for (int l = 1; l < n; l++) {
            string temp = s.substr(i, l);
            if (st.find(temp) != st.end() && solve(i + l, s)) {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        st.insert(wordDict.begin(), wordDict.end());

        return solve(0, s);
    }
};

// TC = O(N * 2^N)
// SC = O(N)
