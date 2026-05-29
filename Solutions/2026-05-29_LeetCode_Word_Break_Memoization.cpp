/*

Problem Name   : Word Break
Platform       : LeetCode
Topic          : Array, Hash Table, String, Dynamic Programming, Trie, Memoization
Problem Link   : https://leetcode.com/problems/word-break/submissions/2016392338/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-29
Approach       : Memoization
Time           : O(N^3)
Space          : O(N)

*/

class Solution {
public:
    int n;
    unordered_set<string> st;
    vector<int> dp;
    bool solve(int i, string& s) {
        if (i >= n)
            return true;

        if (st.find(s) != st.end())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int l = 1; l < n; l++) {
            string temp = s.substr(i, l);
            if (st.find(temp) != st.end() && solve(i + l, s)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        st.insert(wordDict.begin(), wordDict.end());
        dp.assign(n + 1, -1);

        return solve(0, s);
    }
};
