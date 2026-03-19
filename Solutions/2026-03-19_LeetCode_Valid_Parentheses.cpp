/*

Problem Name   : Valid Parentheses
Platform       : LeetCode
Topic          : String, Stack
Problem Link   : https://leetcode.com/problems/valid-parentheses/submissions/1952871710/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        int i = 1;
        st.push(s[0]);
        while (i < n) {
            if ((s[i] == ')' && !st.empty() && st.top() == '(') ||
                (s[i] == '}' && !st.empty() && st.top() == '{') ||
                (s[i] == ']' && !st.empty() && st.top() == '[')) {
                st.pop();
                i++;
            } else {
                st.push(s[i]);
                i++;
            }
        }
        return st.size() == 0;
    }
};
