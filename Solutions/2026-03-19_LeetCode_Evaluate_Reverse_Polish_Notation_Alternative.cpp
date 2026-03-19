/*

Problem Name   : Evaluate Reverse Polish Notation
Platform       : LeetCode
Topic          : Array, Math, Stack
Problem Link   : https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1952883233/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Alternative
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int first = stoi(st.top());
                st.pop();
                int second = stoi(st.top());
                st.pop();

                int result;
                if (s == "+")
                    result = second + first;
                if (s == "-")
                    result = second - first;
                if (s == "*")
                    result = second * first;
                if (s == "/")
                    result = second / first;
                st.push(to_string(result));
            } else
                st.push(s);
        }

        return stoi(st.top());
    }
};
